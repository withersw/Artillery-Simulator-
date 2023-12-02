//
// Created by Ara Cantanhede Araujo on 11/30/23.
//

#ifndef INC_230_07_LAB_GLDEMO__1__HOWITZER_H
#define INC_230_07_LAB_GLDEMO__1__HOWITZER_H

#pragma once
#include "position.h"
#include "angle.h"

class Howitzer {

public:

    // Constructors
    Howitzer(): position(0.0,0.0), angle(), projectile(nullptr), canShoot(true){}
    Howitzer(Position position): position(position), angle(), projectile(nullptr), canShoot(true){}

    // Getters
    Position & getPosition();
    Angle getAngle();
    int* getProjectile();
    bool getCanShoot() const;

    // Setters
    void setPosition(const Position& newPosition);
    void setAngle(const Angle& newAngle);
    void setProjectile(int* newProjectile);

    void setPixelX(double pixelX);

    /*
     * Move the muzzle according to a given angle.
     */
    void moveMuzzle(double radians);

    /*
     * Fire a projectile to the game. It will create a projectile and launch it.
     */
    void fireProjectile();

    void resetProjectile();

    void checkProjectile();

private:
    Position position;
    Angle angle;
    int * projectile;
    bool canShoot;
};


#endif //INC_230_07_LAB_GLDEMO__1__HOWITZER_H
