//
// Created by Wade Withers on 11/18/23.
//

#include "acceleration.h"
#include <cmath>

#define MASS 46.7

Acceleration::Acceleration() : acceleration(0.0), verticalAcceleration(0.0), horizontalAcceleration(0.0) {}

Acceleration::Acceleration(double acceleration, Angle angle) {
    this->acceleration = acceleration;
    this->verticalAcceleration = cos(angle.getRadians()) * acceleration;
    this->horizontalAcceleration = sin(angle.getRadians()) * acceleration;

}

double Acceleration::getAcceleration() {
    return this->acceleration;
}

double Acceleration::getVerticalAcceleration() {
    return this->verticalAcceleration;
}

double Acceleration::getHorizontalAcceleration() {
    return this->horizontalAcceleration;
}

void Acceleration::setAcceleration(double acceleration) {
    this->acceleration = acceleration;
}

void Acceleration::setVerticalAcceleration(double verticalAcceleration) {
    this->verticalAcceleration = verticalAcceleration;
}

void Acceleration::setHorizontalAcceleration(double horizontlAcceleration) {
    this->horizontalAcceleration = horizontlAcceleration;
}

void Acceleration::updateAccelerationFromDrag(double dragForce, Angle angle) {
    double accelerationChange = dragForce / MASS;
    this->verticalAcceleration = cos(angle.getRadians()) * accelerationChange;
    this->horizontalAcceleration = sin(angle.getRadians()) * accelerationChange;
}