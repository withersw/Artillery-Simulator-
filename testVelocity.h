//
// Created by Ara Araujo on 11/18/23.
//

#ifndef INC_230_07_LAB_GLDEMO__1__TESTVELOCITY_H
#define INC_230_07_LAB_GLDEMO__1__TESTVELOCITY_H

#pragma once

#include <iostream>
#include "velocity.h"
#include "angle.h"
#include <cassert>
#include <cmath>

class TestVelocity
{
public:
    void run()
    {
        defaultConstructor();
        nonDefaultConstructorOne();
        nonDefaultConstructorTwo();
        getVelocities();
        setVelocities();
        updateVelocity_negativeAcceleration();
        updateVelocity_positiveAcceleration();
        updateVelocity_zeroAcceleration();
        computeVerticalVelocity_ninetyCosinePositiveVelocity();
        computeVerticalVelocity_fortyFiveCosinePositiveVelocity();
        computeVerticalVelocity_zeroCosinePositiveVelocity();
        computeVerticalVelocity_minusFortyFiveCosinePositiveVelocity();
        computeVerticalVelocity_minusNinetyFiveCosinePositiveVelocity();
        computeHorizontalVelocity_ninetySinePositiveVelocity();
        computeHorizontalVelocity_fortyFiveSinePositiveVelocity();
        computeHorizontalVelocity_zeroSinePositiveVelocity();
        computeHorizontalVelocity_minusFortyFiveSinePositiveVelocity();
        computeHorizontalVelocity_minusNinetySinePositiveVelocity();
    }

private:
    // utility function because floating point numbers are approximations
    bool closeEnough(double value, double test, double tolerence) const
    {
        double difference = value - test;
        return (difference >= -tolerence) && (difference <= tolerence);
    }
    double convertDegreesToRadians(double degrees) const
    {
        // Setting up radians variable.
        double radians;

        // Converting degrees to radians.
        radians = ((degrees / 360) * (2 * M_PI));

        // Normalize the radians between 0 and 2pi.
        if (radians > 2 * M_PI || radians < 0)
        {
            radians = fmod(radians, 2 * M_PI);
        }

        // Returning radians.
        return radians;
    }

    /*
     * Constructors tests.
     */
    void defaultConstructor() const
    {
        // Setup
        // Exercise
        Velocity velocity;
        // verify
        assert(velocity.velocity == 0.0);
        assert(velocity.verticalVelocity == 0.0);
        assert(velocity.horizontalVelocity == 0.0);
        // Teardown
    }

    void nonDefaultConstructorOne() const
    {
        // Setup
        Angle angle(M_PI/4);
        double tolerance = 0.01;
        // Exercise
        Velocity velocity(200.0,angle);
        // verify
        assert(velocity.velocity == 200.0);
        assert(closeEnough(velocity.verticalVelocity,141.4213,tolerance));
        assert(closeEnough(velocity.horizontalVelocity,141.4213,tolerance));
        // Teardown
    }

    void nonDefaultConstructorTwo() const
    {
        // Setup
        double tolerance = 0.01;
        // Exercise
        Velocity velocity(200.0,250.0);
        // verify
        assert(closeEnough(velocity.velocity,320.15,tolerance));
        assert(closeEnough(velocity.verticalVelocity,200.0,tolerance));
        assert(closeEnough(velocity.horizontalVelocity,250.0,tolerance));
        // Teardown
    }

    /*
     * Testing getters.
     */
    void getVelocities() const
    {
        // Setup
        double tolerance = 0.01;
        // Exercise
        Velocity velocity(200.0,250.0);
        // verify
        assert(closeEnough(velocity.getVelocity(),320.15,tolerance));
        assert(closeEnough(velocity.getVerticalVelocity(),200.0,tolerance));
        assert(closeEnough(velocity.getHorizontalVelocity(),250.0,tolerance));
        // Teardown

    }

    /*
     * Testing setters.
     */
    void setVelocities() const
    {
        // Setup
        // Exercise
        Velocity velocity;
        velocity.setVelocity(300.0);
        velocity.setVerticalVelocity(200.0);
        velocity.setHorizontalVelocity(250.0);
        // verify
        assert(velocity.velocity == 300.0);
        assert(velocity.verticalVelocity == 200.0);
        assert(velocity.horizontalVelocity == 250.0);
        // Teardown
    }

    /*
     * Testing updating velocity from acceleration.
     */
    void updateVelocity_negativeAcceleration() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.updateVelocity(100,-9.8,0.01);
        // Verify
        assert(closeEnough(99.902,result,tolerance));
        // Teardown
    }

    void updateVelocity_zeroAcceleration() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.updateVelocity(100,0,0.01);
        // Verify
        assert(closeEnough(100.00,result,tolerance));
        // Teardown
    }

    void updateVelocity_positiveAcceleration() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.updateVelocity(100.0,9.8,0.01);
        // Verify
        assert(closeEnough(100.098,result,tolerance));
        // Teardown
    }

    /*
     * Compute vertical velocity tests.
     */
    void computeVerticalVelocity_ninetyCosinePositiveVelocity() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.computeVerticalVelocity(M_PI/2,100);
        // Verify
        assert(closeEnough(0,result,tolerance));
        // Teardown
    }

    void computeVerticalVelocity_fortyFiveCosinePositiveVelocity() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.computeVerticalVelocity(M_PI/4,100);
        // Verify
        assert(closeEnough(70.710678, result, tolerance));
        // Teardown
    }

    void computeVerticalVelocity_zeroCosinePositiveVelocity() const
    {
        // Setup
        Velocity velocity;
        // Exercise
        double result = velocity.computeVerticalVelocity(0,100);
        // Verify
        assert(result == 100.0);
        // Teardown
    }

    void computeVerticalVelocity_minusFortyFiveCosinePositiveVelocity() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.computeVerticalVelocity(-M_PI/4,100);
        // Verify
        assert(closeEnough(70.710678, result, tolerance));
        // Teardown
    }

    void computeVerticalVelocity_minusNinetyFiveCosinePositiveVelocity() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.computeVerticalVelocity(-M_PI/2,100);
        // Verify
        assert(closeEnough(0, result, tolerance));
        // Teardown
    }

    /*
     * Compute horizontal velocity tests.
     */
    void computeHorizontalVelocity_ninetySinePositiveVelocity() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.computeHorizontalVelocity(M_PI/2,100);
        // Verify
        assert(closeEnough(100, result, tolerance));
        // Teardown
    }

    void computeHorizontalVelocity_fortyFiveSinePositiveVelocity() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.computeHorizontalVelocity(M_PI/4,100);
        // Verify
        assert(closeEnough(70.710678, result, tolerance));
        // Teardown
    }

    void computeHorizontalVelocity_zeroSinePositiveVelocity() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.computeHorizontalVelocity(0,100);
        // Verify
        assert(closeEnough(0, result, tolerance));
        // Teardown
    }

    void computeHorizontalVelocity_minusFortyFiveSinePositiveVelocity() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.computeHorizontalVelocity(-M_PI/4,100);
        // Verify
        assert(closeEnough(-70.710678, result, tolerance));
        // Teardown
    }

    void computeHorizontalVelocity_minusNinetySinePositiveVelocity() const
    {
        // Setup
        Velocity velocity;
        double tolerance = 0.01;
        // Exercise
        double result = velocity.computeHorizontalVelocity(-M_PI/2,100);
        // Verify
        assert(closeEnough(-100, result, tolerance));
        // Teardown
    }
};


#endif //INC_230_07_LAB_GLDEMO__1__TESTVELOCITY_H
