//
// Created by Wade Withers on 11/18/23.
//

#ifndef INC_230_07_LAB_GLDEMO_1_ACCELERATION_H
#define INC_230_07_LAB_GLDEMO_1_ACCELERATION_H

#include "angle.h"

class TestAcceleration;

class Acceleration {
private:
    double acceleration{};
    double verticalAcceleration{};
    double horizontalAcceleration{};

public:
    friend TestAcceleration;

    // constructors
    Acceleration();
    Acceleration(double acceleration, Angle angle);

    // Getters
    double getAcceleration();
    double getVerticalAcceleration();
    double getHorizontalAcceleration();

    // Setters
    void setAcceleration(double acceleration);
    void setVerticalAcceleration(double verticalAcceleration);
    void setHorizontalAcceleration(double horizontalAcceleration);

    // Update acceleration due to drag force.
    void updateAccelerationFromDrag(double dragForce, Angle angle);

    /*// Compute vertical acceleration
    double computeVerticalAcceleration(double acceleration, double radians);

    // Compute horizontal acceleration
    double computeHorizontalAcceleration(double acceleration, double radians);

    // Compute acceleration from force
    double computeAccelerationFromForce(double force);
*/
};


#endif //INC_230_07_LAB_GLDEMO_1_ACCELERATION_H
