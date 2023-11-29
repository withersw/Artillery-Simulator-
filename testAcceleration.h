//
// Created by Wade Withers on 11/18/23.
//

#ifndef INC_230_07_LAB_GLDEMO__1__TESTACCELERATION_H
#define INC_230_07_LAB_GLDEMO__1__TESTACCELERATION_H

#pragma once

#include "acceleration.h"
#include "angle.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std; // For debugging. Delete this line when finished.

/********************************
 * TEST ACCELERATION
 * Unit test for Acceleration
 ********************************/
class TestAcceleration
{
public:
    void run()
    {
        test_defaultConstructor();
        test_nonDefaultConstructor();
        test_getAccelerations();
        test_setAccelerations();
        test_computeVerticalAcceleration_posAccelerationZeroAngle();
        test_computeVerticalAcceleration_posAcceleration90Angle();
        test_computeVerticalAcceleration_negAcceleration45Angle();
        test_computeVerticalAcceleration_ZeroAccelerationZeroAngle();
        test_computeHorizontalAcceleration_posAccelerationZeroAngle();
        test_computeHorizontalAcceleration_posAcceleration90Angle();
        test_computeHorizontalAcceleration_negAcceleration45Angle();
        test_computeHorizontalAcceleration_ZeroAccelerationZeroAngle();
    }

private:
    // utility function because floating point numbers are approximations
    bool closeEnough(double value, double test, double tolerence) const
    {
        double difference = value - test;
        return (difference >= -tolerence) && (difference <= tolerence);
    }

    /*
     * Default Concstructor test
     */
    void test_defaultConstructor() const
    {
        // Setup
        Acceleration acceleration;

        // Exercise

        // Verify
        assert(acceleration.acceleration == 0.0);
        assert(acceleration.verticalAcceleration == 0.0);
        assert(acceleration.horizontalAcceleration == 0.0);

        // Teardown
    }

    /*
     * Default Non-Concstructor test
     */
    void test_nonDefaultConstructor() const
    {
        // Setup
        Angle angle(M_PI/4);
        //angle.set(M_PI/4);


        double tolerance = 0.1;

        // Exercise
        Acceleration acceleration(1, angle);

        // Verify
        assert(closeEnough(1.0, acceleration.acceleration, tolerance));
        assert(closeEnough(0.7071, acceleration.verticalAcceleration, tolerance));
        assert(closeEnough(0.7071, acceleration.horizontalAcceleration, tolerance));

        // Teardown
    }

    /*
    * Testing getters
    */
    void test_getAccelerations() const
    {
        // Setup
        Angle angle(0.0);
        Acceleration acceleration(1.0, angle);
        double tolerance = 0.01;
        // Exercise

        // Verify
        assert(acceleration.getAcceleration() == 1.0);
        assert(closeEnough(1.0, acceleration.getVerticalAcceleration(), tolerance));
        assert(acceleration.getHorizontalAcceleration() == 0.0);

        // Teardown
    }

    /*
    * Testing setters
    */
    void test_setAccelerations() const
    {
        // Setup

        Acceleration acceleration;
        acceleration.setAcceleration(100.0);
        acceleration.setVerticalAcceleration(75.0);
        acceleration.setHorizontalAcceleration(50.0);

        // Exercise

        // Verify
        assert(acceleration.acceleration == 100.0);
        assert(acceleration.verticalAcceleration == 75.0);
        assert(acceleration.horizontalAcceleration == 50.0);

        // Teardown
    }

    /*
    * Compute vertical acceleration tests
    */
    void test_computeVerticalAcceleration_posAccelerationZeroAngle() const
    {
        // Setup
        Acceleration acceleration;
        double tolerance = 0.01;
        acceleration.acceleration = 1.0;

        // Exercise
        acceleration.updateAccelerationFromDrag(10.0, 0.0);

        // Verify
        assert(closeEnough(0.7859, acceleration.getVerticalAcceleration(), tolerance));

        // Teardown
    }

    void test_computeVerticalAcceleration_posAcceleration90Angle() const
    {
        // Setup
        Acceleration acceleration;
        double tolerance = 0.01;
        acceleration.acceleration = 1.0;

        // Exercise
        acceleration.updateAccelerationFromDrag(10.0, M_PI);

        // Verify
        assert(closeEnough(-0.7859, acceleration.verticalAcceleration, tolerance));

        // Teardown
    }

    void test_computeVerticalAcceleration_negAcceleration45Angle() const
    {
        // Setup
        Acceleration acceleration;
        double tolerance = 0.01;
        acceleration.acceleration = -1.0;

        // Exercise
        acceleration.updateAccelerationFromDrag(10.0, M_PI/4);

        // Verify
        assert(closeEnough(-0.8585, acceleration.verticalAcceleration, tolerance));

        // Teardown
    }

    void test_computeVerticalAcceleration_ZeroAccelerationZeroAngle() const
    {
        // Setup
        Acceleration acceleration;
        double tolerance = 0.01;
        acceleration.acceleration = 0.0;

        // Exercise
        acceleration.updateAccelerationFromDrag(0.0, 0.0);

        // Verify
        assert(closeEnough(0.0, acceleration.verticalAcceleration, tolerance));

        // Teardown
    }

    /*
     * Compute horizontal acceleration tests
     */
    void test_computeHorizontalAcceleration_posAccelerationZeroAngle() const
    {
        // Setup
        Acceleration acceleration;
        double tolerance = 0.01;
        acceleration.acceleration = 1.0;

        // Exercise
        acceleration.updateAccelerationFromDrag(10.0, 0);

        // Verify
        assert(closeEnough(0.0, acceleration.horizontalAcceleration, tolerance));

        // Teardown
    }

    void test_computeHorizontalAcceleration_posAcceleration90Angle() const
    {
        // Setup
        Acceleration acceleration;
        double tolerance = 0.01;
        acceleration.acceleration = 1.0;

        // Exercise
        acceleration.updateAccelerationFromDrag(10.0, M_PI/2);

        // Verify
        assert(closeEnough(0.7859, acceleration.horizontalAcceleration, tolerance));

        // Teardown
    }

    void test_computeHorizontalAcceleration_negAcceleration45Angle() const
    {
        // Setup
        Acceleration acceleration;
        double tolerance = 0.01;
        acceleration.acceleration = -1.0;

        // Exercise
        acceleration.updateAccelerationFromDrag(10.0, M_PI/4);

        // Verify
        assert(closeEnough(-0.8585, acceleration.horizontalAcceleration, tolerance));

        // Teardown
    }

    void test_computeHorizontalAcceleration_ZeroAccelerationZeroAngle() const
    {
        // Setup
        Acceleration acceleration;
        double tolerance = 0.01;
        acceleration.acceleration = 0.0;

        // Exercise
        acceleration.updateAccelerationFromDrag(0.0, 0.0);

        // Verify
        assert(closeEnough(0.0, acceleration.horizontalAcceleration, tolerance));

        // Teardown
    }

};

#endif //INC_230_07_LAB_GLDEMO__1__TESTACCELERATION_H
