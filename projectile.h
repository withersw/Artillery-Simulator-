//
// Created by Wade Withers on 12/1/23.
//

#ifndef INC_230_07_LAB_GLDEMO__1__PROJECTILE_H
#define INC_230_07_LAB_GLDEMO__1__PROJECTILE_H

#define MASS 46.7;

#include "velocity.h"
#include "position.h"
#include "acceleration.h"
#include "angle.h"
#include "constants.h"
#include <map>

class Projectile {
public:
    // Constructors
    Projectile();
    Projectile(Position position);

    // Getters
    Velocity getVelocity();
    Position getPosition();
    Acceleration getAcceleration();
    Angle getAngle();

    // Setters
    void setVelocity(Velocity newVelocity);
    void setPosition(Position newPosition);
    void setAcceleration(Acceleration newAcceleration);
    void setAngle(Angle newAngle);

    // Update position of projectile.
    void moveProjectile();
private:
    Velocity velocity;
    Position position;
    Acceleration acceleration;
    Angle angle;

    // Perform Linear Interpolation.
    double linearInterpolation(double dCoord0, double rCoord0,double dCoord1, double rCoord1,double dCoordMiddle);

    // Update the velocity of the projectile.
    double updateVelocity(double v0, double acceleration);

    // Compute distance traveled in given time interval.
    double computeDistance(double originalPosition, double velocity, double acceleration, double time);

    // Get value from given altitude.
    //pair<double, double> getValuesFromConstants(double altitude, map<double, double> values);

    // Update the angle of projectile.
    void updateAngle();

    // Update position of the projectile.
    void updatePosition();

    double calculateGravity(double altitude, pair<double,double> altitudeValues, Constants constants);

    double updateDragCoefficient(double altitude, double currentSpeedMach, Constants constants, pair<double,double> machDragValues);

    double computeDrag(double currentSpeed, double airDensity, double dragCoefficient, double VelocityComponent);
};


#endif //INC_230_07_LAB_GLDEMO__1__PROJECTILE_H
