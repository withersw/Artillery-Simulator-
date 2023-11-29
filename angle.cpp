//
// Created by Wade Withers on 11/18/23.
//

#include "angle.h"

Angle::Angle() {
}

Angle::Angle(double radians) {
    this->radians = radians;
}

double Angle::getRadians() {
    return radians;
}

void Angle::set(double radians) {
    this->radians = radians;
}