//
// Created by Ara Araujo on 11/18/23.
//

#include <iostream>
#include "velocity.h"
#include "cmath"

Velocity::Velocity(double velocity, Angle angle) {
    this->verticalVelocity = computeVerticalVelocity(angle.getRadians(),velocity);
    this->horizontalVelocity = computeHorizontalVelocity(angle.getRadians(),velocity);
}

Velocity::Velocity(double verticalVelocity, double horizontalVelocity) {
    this->verticalVelocity = verticalVelocity;
    this->horizontalVelocity = horizontalVelocity;
}

double Velocity::getVelocity() {
    return sqrt(pow(verticalVelocity, 2) + pow(horizontalVelocity, 2));;
}

double Velocity::getVerticalVelocity() {
    return this->verticalVelocity;
}

double Velocity::getHorizontalVelocity() {
    return this->horizontalVelocity;
}

//void Velocity::setVelocity(double newVelocity) {
//    this->velocity = newVelocity;
//}

void Velocity::setVerticalVelocity(double newVerticalVelocity) {
    this->verticalVelocity = newVerticalVelocity;
}

void Velocity::setHorizontalVelocity(double newHorizontalVelocity) {
    this->horizontalVelocity = newHorizontalVelocity;
}

double Velocity::updateVelocity(double v0, double acceleration, double time) {
    double newVelocity = v0 + (acceleration * time);
    return newVelocity;
}

double Velocity::computeVerticalVelocity(double radians, double totalVelocity) {
    double verticalVelocityComponent = totalVelocity * cos(radians);
    return verticalVelocityComponent;
}

double Velocity::computeHorizontalVelocity(double radians, double totalVelocity) {
    double horizontalVelocityComponent = totalVelocity * sin(radians);
    return horizontalVelocityComponent;
}


