#pragma once

#include <iostream>
#include <istream>
#include <cassert>
#include <ostream>
#include <cmath>
#include <iomanip>

#define TWO_PI 6.28318530718

using namespace std;

class TestAngle;

/************************************
 * ANGLE
 ************************************/
class Angle
{
    friend TestAngle;
    friend istream& operator>>(istream & in, Angle & angle);
    friend ostream & operator<<(ostream & out, const Angle & rhs);

public:
    // Default constructor
    Angle() : radians(0.0) {}
    Angle(const Angle & rhs) : radians(rhs.radians) {}
    Angle(double degrees) : radians(convertToRadians(degrees))
    {
        setDegrees(degrees);
    }

    // Getters
    double getDegrees() const
    {
        return convertToDegrees(radians);
    }
    double getRadians() const
    {
        return radians;
    }

    // Setters
    void setDegrees(double degrees)
    {
        radians = normalize(convertToRadians(degrees));
    }
    void setRadians(double radians)
    {
        this->radians = normalize(radians);
    }

    // Display
    void display(ostream & out) const
    {
        out.precision(1);
        out.setf(ios::fixed | ios::showpoint);
        out << getDegrees();
    }

    // Assignment Operator
    Angle & operator=(const Angle & rhs)
    {
        radians = rhs.radians;
        return *this;
    }

    // Negative Operator
    Angle operator-() const
    {
        return Angle(convertToDegrees(radians) + 180);
    }

    // Equals Operator
    bool operator==(const Angle & rhs) const
    {
        return radians == rhs.radians;
    }

    // Not Equals Operator
    bool operator!=(const Angle & rhs) const
    {
        return radians != rhs.radians;
    }

    Angle & operator++()
    {
        radians += convertToRadians(1.0);
        radians = normalize(radians);
        return *this;
    }

    Angle operator++(int postfix)
    {
        Angle angleReturn(*this);
        radians += convertToRadians(1.0);
        radians = normalize(radians);
        return angleReturn;
    }

    Angle & operator--()
    {
        radians -= convertToRadians(1.0);
        radians = normalize(radians);
        return *this;
    }

    Angle operator--(int postfix)
    {
        Angle angleReturn(*this);
        radians -= convertToRadians(1.0);
        radians = normalize(radians);
        return angleReturn;
    }


private:
    // Convert functions
    double convertToDegrees(double newRadians) const
    {
//        cout << normalize(newRadians) / TWO_PI * 360.0 << endl;
        return normalize(newRadians) / TWO_PI * 360.0;
    }

    double convertToRadians(double degrees) const
    {
        return normalize(degrees / 360.0 * TWO_PI);
    }

    // Normalize
    double normalize(double radians) const
    {
        if (radians >= TWO_PI)
        {
            double multiples = floor(radians / TWO_PI);
            assert(radians - TWO_PI * multiples >= 0.0);
            assert(radians - TWO_PI * multiples <= TWO_PI);
            return radians - (TWO_PI * multiples);
        }
        else if (radians < 0.0)
        {
            double multiples = ceil(-radians / TWO_PI);
            assert(TWO_PI * multiples + radians >= 0.0);
            assert(TWO_PI * multiples + radians <= TWO_PI);
            return TWO_PI * multiples + radians;
        }

        assert(0.0 <= radians && radians <= TWO_PI);
        return radians;
    }

    double radians;
};


// Insertion Operator
ostream & operator<<(ostream & out, const Angle & rhs)
{
    out.setf(ios::fixed | ios::showpoint);
    out.precision(1);
    out << rhs.getDegrees();
    return out;
}

// Extraction Operator
istream & operator>>(istream & in, Angle & rhs)
{
    double newAngle;
    in >> newAngle;
    if (!in.fail()){
        rhs.radians = rhs.convertToRadians(newAngle);
    }
    return in;
}

