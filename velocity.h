//
// Created by Ara Araujo on 11/18/23.
//

#ifndef INC_230_07_LAB_GLDEMO__1__VELOCITY_H
#define INC_230_07_LAB_GLDEMO__1__VELOCITY_H


#include "angle.h"
#pragma once
class TestVelocity;

class Velocity {

public:
    friend TestVelocity;

    // constructors
    Velocity() : velocity(0.0), verticalVelocity(0.0), horizontalVelocity(0.0) {}
    Velocity(double velocity, Angle angle);
    Velocity(double verticalVelocity, double horizontalVelocity);

    // Getters
    double getVelocity();
    double getVerticalVelocity();
    double getHorizontalVelocity();

    // Setters
    void setVelocity(double newVelocity);
    void setVerticalVelocity(double newVerticalVelocity);
    void setHorizontalVelocity(double newHorizontalVelocity);

    /*
     * Update velocity according to a given acceleration
     */
    double updateVelocity(double v0, double acceleration, double time);

    /*
     * Computer vertical velocity from total velocity
     */
    double computeVerticalVelocity(double radians, double velocity);

    /*
     * Computer vertical velocity from total velocity
     */
    double computeHorizontalVelocity(double radians, double velocity);

private:
    double velocity;
    double verticalVelocity;
    double horizontalVelocity;

};


#endif //INC_230_07_LAB_GLDEMO__1__VELOCITY_H
