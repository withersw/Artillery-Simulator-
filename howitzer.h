//
// Created by Ara Cantanhede Araujo on 11/30/23.
//

#ifndef INC_230_07_LAB_GLDEMO__1__HOWITZER_H
#define INC_230_07_LAB_GLDEMO__1__HOWITZER_H

#pragma once
#include "position.h"
#include "angle.h"
#include "projectile.h"

class Howitzer {

public:

    // Constructors
    Howitzer(): position(0.0,0.0), angle(), canShoot(true){}
    Howitzer(Position position): position(position), angle(), canShoot(true){}

    // Getters
    Position & getPosition();
    Angle getAngle();
    Projectile getProjectile();
    bool getCanShoot() const;

    // Setters
    void setPosition(const Position& newPosition);
    void setAngle(const Angle& newAngle);
    void setProjectile(Projectile newProjectile);

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

    void updateProjectilePosition();

private:
    Position position;
    Angle angle;
    Projectile  projectile;
    bool canShoot;
};


#endif //INC_230_07_LAB_GLDEMO__1__HOWITZER_H
