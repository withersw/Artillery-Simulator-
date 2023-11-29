//
// Created by Wade Withers on 11/18/23.
//

#ifndef INC_230_07_LAB_GLDEMO__1__ANGLE_H
#define INC_230_07_LAB_GLDEMO__1__ANGLE_H

class Angle {
public:
    Angle();
    Angle(double radians);

    void set(double radians);
    double getRadians();

private:
    double radians;
};


#endif //INC_230_07_LAB_GLDEMO__1__ANGLE_H
