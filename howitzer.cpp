//
// Created by Ara Cantanhede Araujo on 11/30/23.
//

#include "howitzer.h"
#include <vector>

/*
 * GETTERS
 */
Position & Howitzer::getPosition() {
    return this->position;
}

Angle Howitzer::getAngle() {
    return this->angle;
}

vector<Projectile>* Howitzer::getProjectile() {
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

//void Howitzer::setProjectile(Projectile newProjectile) {
//    this->projectile = &newProjectile;
//}

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
    Projectile proj = Projectile(this->position, this->angle);
    this->projectile->push_back(proj);
}

void Howitzer::resetProjectile() {
    this->projectile->clear();
}

void Howitzer::updateProjectilePosition()
{
    for(auto proj : *this->projectile){
        proj.moveProjectile();
    }
}