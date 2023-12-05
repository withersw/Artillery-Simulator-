//
// Created by Wade Withers on 12/1/23.
//

#define TIME 0.5
#define DIAMETER 154.89
#define SPEED 827.0

#include "projectile.h"
#include "constants.h"
#include <cmath>


Projectile::Projectile() {}

Projectile::Projectile(Position newPosition, Angle newAngle) {
    this->position = newPosition;
    this->angle = newAngle;
    this->velocity.setVerticalVelocity(SPEED * cos(this->angle.getRadians()));
    this->velocity.setHorizontalVelocity(SPEED * sin(this->angle.getRadians()));
}

/********************************
 * GETTERS
 ********************************/
Velocity Projectile::getVelocity() {
    return velocity;
}

Position Projectile::getPosition() {
    return position;
}

Acceleration Projectile::getAcceleration() {
    return acceleration;
}

Angle Projectile::getAngle() {
    return angle;
}

/********************************
 * SETTERS
 ********************************/
void Projectile::setVelocity(Velocity newVelocity) {
    this->velocity = newVelocity;
}

void Projectile::setPosition(Position newPosition) {
    this->position = newPosition;
}

void Projectile::setAcceleration(Acceleration newAcceleration) {
    this->acceleration = newAcceleration;
}

void Projectile::setAngle(Angle newAngle) {
    this->angle = newAngle;
}

/********************************
 * MOVE PROJECTILE
 * Update position of the projectile.
 ********************************/
void Projectile::moveProjectile() {
    updatePosition();
}

/********************************
 * LINEAR INTERPOLATION
 * Perform linear interpolation with given sets of coordinates.
 ********************************/
double Projectile::linearInterpolation(double dCoord0, double rCoord0, double dCoord1, double rCoord1, double dCoordMiddle) {
    double rCoordMiddle = rCoord0 + (dCoordMiddle - dCoord0) * ((rCoord1 - rCoord0) / (dCoord1 - dCoord0));
    return rCoordMiddle;
}

/********************************
 * UPDATE VELOCITY
 * Update the velocity of the projectile.
 ********************************/
double Projectile::updateVelocity(double startingVelocity, double acceleration) {
    double newVelocity = startingVelocity + (acceleration * TIME);
    return newVelocity;
}

/********************************
 * COMPUTE DISTANCE
 * Compute the distance that the projectile travels in given time interval(frame).
 ********************************/
double Projectile::computeDistance(double originalPosition, double velocity, double acceleration, double time) {
    // New position variable.
    double newPosition;

    // Calculating the new position according to the given equation.
    newPosition = originalPosition + (velocity * time) + (0.5 * acceleration * (time * time));

    // returning new position.
    return newPosition;
}

/********************************
 * GET VALUES FROM CONSTANTS
 * Find constants value based off of altitude.
 ********************************/
//pair<double, double> Projectile::getValuesFromConstants(double altitude, map<double, double> values) {
//
//    // Creating result pair
//    std::pair<double, double> result;
//
//    // Setting the current value to begin;
//    auto current = values.begin();
//
//    // Creating a for loop and setting up a value called next
//    // to hold the iterator next to current, so we can compare
//    // the lower and upper value.
//    for(auto next = std::next(current); next != values.end(); ++current, ++next){
//        if(altitude >= current->first && altitude < next->first){
//            result.first = current->first;
//            result.second = next->first;
//            return result;
//        }
//    }
//
//    // If the result never received a value it means that is
//    // higher than the last values, so we will set both values
//    // to the last value
//    if (result.second == 0){
//        result.first = current->first;
//        result.second = current->first;
//    }
//
//    // Return pair with the lower and upper value.
//    return result;
//}

/********************************
 * UPDATE ANGLE
 * Update angle from horizontal and vertical velocity.
 ********************************/
void Projectile::updateAngle() {
    this->angle.setRadians(atan2(velocity.getHorizontalVelocity(), velocity.getVerticalVelocity()));
}

/********************************
 * UPDATE POSITION
 * Update the position of the projectile.
 ********************************/
void Projectile::updatePosition() {

    pair<double,double> altitudeValues;
    pair<double,double> altitudeDensityValues;
    pair<double,double> altitudeSoundValues;
    pair<double,double> machDragValues;

    Constants constants;

    updateAngle();

    double altitude = position.getMetersY();

    // Update gravity from altitude.
    double gravity = calculateGravity(altitude, altitudeValues, constants);

    // Update air density from altitude.
    altitudeDensityValues = constants.getValueFromConstants(altitude, constants.getDensity());
    double airDensity = linearInterpolation(
            altitudeDensityValues.first,
            constants.getDensity().find(altitudeDensityValues.first)->second,
            altitudeDensityValues.second,
            constants.getDensity().find(altitudeDensityValues.second)->second,
            altitude);

    double currentSpeed = sqrt(pow(velocity.getVerticalVelocity(), 2) + pow(velocity.getVerticalVelocity(), 2));


    // Update speed of sound from altitude.
    altitudeSoundValues = constants.getValueFromConstants(altitude, constants.getSpeedOfSound());
    double speedOfSound = linearInterpolation(
            altitudeSoundValues.first,
            constants.getSpeedOfSound().find(altitudeSoundValues.first)->second,
            altitudeSoundValues.second,
            constants.getSpeedOfSound().find(altitudeSoundValues.second)->second,
            altitude);

    // Get current speed in machs.
    double currentSpeedMach = currentSpeed / speedOfSound;

    // Update drag coefficient from altitude.
    double dragCoefficient = updateDragCoefficient(altitude, currentSpeedMach, constants, machDragValues);

    // Compute total drag
    double dragTotal = computeDrag(currentSpeed, airDensity, dragCoefficient);

    acceleration.updateAccelerationFromDrag(dragTotal, this->angle);

    double netForce = - gravity - acceleration.getVerticalAcceleration();

    // Update velocity from acceleration.
    velocity.setVerticalVelocity(velocity.updateVelocity(velocity.getVerticalVelocity(),netForce,0.5));
    velocity.setHorizontalVelocity(velocity.updateVelocity(velocity.getHorizontalVelocity(),this->acceleration.getHorizontalAcceleration(),0.5));

    // Update position of the projectile.
    position.setMetersX(computeDistance(position.getMetersX(), velocity.getHorizontalVelocity(), -acceleration.getHorizontalAcceleration(), TIME));
    position.setMetersY(computeDistance(position.getMetersY(), velocity.getVerticalVelocity(), netForce, TIME));
}

double Projectile::calculateGravity(double altitude, pair<double,double> altitudeValues, Constants constants) {
    altitudeValues = constants.getValueFromConstants(altitude, constants.getGravity());
    double gravity = linearInterpolation(
            altitudeValues.first,
            constants.getGravity().find(altitudeValues.first)->second,
            altitudeValues.second,
            constants.getGravity().find(altitudeValues.second)->second,
            altitude);
    return gravity;
}

double Projectile::updateDragCoefficient(double altitude, double currentSpeedMach, Constants constants, pair<double,double> machDragValues) {

    // Update drag coefficient from altitude.
    double dragCoefficient;
    if (currentSpeedMach < 0.300){
        dragCoefficient = constants.getDrag().find(.300)->second;
    }else{
        machDragValues = constants.getValueFromConstants(currentSpeedMach, constants.getDrag());
        dragCoefficient = linearInterpolation(
                machDragValues.first,
                constants.getDrag().find(machDragValues.first)->second,
                machDragValues.second,
                constants.getDrag().find(machDragValues.second)->second,
                currentSpeedMach);
    };

    return dragCoefficient;
}

double Projectile::computeDrag(double currentSpeed, double airDensity, double dragCoefficient) {
    // Get area of projectile.
    double radiusMeters = (DIAMETER / 2)/1000;
    double area = M_PI * (radiusMeters * radiusMeters);

    // Compute drag
    double drag = 0.5 * dragCoefficient * airDensity * (currentSpeed * currentSpeed) * area;

    return drag;;
}

