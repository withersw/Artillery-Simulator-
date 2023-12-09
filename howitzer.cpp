//
// Created by Ara Cantanhede Araujo on 11/30/23.
//

#include "howitzer.h"

/*
 * GETTERS
 */
Position & Howitzer::getPosition() {
    return this->position;
}

Angle Howitzer::getAngle() {
    return this->angle;
}

Projectile* Howitzer::getProjectile() {
    return this->projectile;
}

/*
 * SETTERS
 */

void Howitzer::setPosition(const Position& newPosition) {
    this->position = newPosition;
}

void Howitzer::setAngle(const Angle& newAngle) {
    this->angle = newAngle;
}

void Howitzer::setProjectile(Projectile newProjectile) {
    this->projectile = &newProjectile;
}

void Howitzer::setPixelX(double pixelX) {
    this->position.setPixelsX(pixelX);
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
    this->projectile = new Projectile[20];
    for (int i = 0; i < 20; ++i) {
        // Initialize each object with specific parameters
        projectile[i] = Projectile(this->position,this->angle);
    }
}

void Howitzer::resetProjectile() {
    this->projectile = nullptr;
}

void Howitzer::updateProjectilePosition()
{
    for (int i = 0; i < 20; ++i) {
        // Initialize each object with specific parameters
        projectile[i].moveProjectile();
    }
//    this->projectile->moveProjectile();
}