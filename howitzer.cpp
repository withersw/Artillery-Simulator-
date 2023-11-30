//
// Created by Ara Cantanhede Araujo on 11/30/23.
//

#include "howitzer.h"

/*
 * GETTERS
 */
Position Howitzer::getPosition() {
    return this->position;
}

Angle Howitzer::getAngle() {
    return this->angle;
}

int* Howitzer::getProjectile() {
    return this->projectile;
}

/*
 * SETTERS
 */

void Howitzer::setPosition(Position newPosition) {
    this->position = newPosition;
}

void Howitzer::setAngle(Angle newAngle) {
    this->angle = newAngle;
}

void Howitzer::setProjectile(int* newProjectile) {
    this->projectile = newProjectile;
}

/*
 * MOVE MUZZLE
 * This function will receive a radians values and update the angle of the
 * howitzer, which is the angle of the muzzle. This will change the direction
 * in which the muzzle is pointing to.
 */

void Howitzer::moveMuzzle(double radians) {
    this->angle+=radians;
}

/*
 * FIRE PROJECTILE
 * This function will create a projectile object and set to the projectile attribute
 * and fire it.
 */

void Howitzer::fireProjectile() {
    int value = 1;
    int *newProjectile;
    newProjectile = &value;
    this->projectile = newProjectile;
}