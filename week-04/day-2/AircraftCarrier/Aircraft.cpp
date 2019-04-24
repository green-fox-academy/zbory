//
// Created by zbora on 2019-04-23.
//

#include <iostream>
#include "Aircraft.h"

Aircraft::Aircraft(int baseDamage, int maxAmmo)
{
    this->baseDamage = baseDamage;
    this->maxAmmo = maxAmmo;
    currentAmmo = 0;
}

std::string Aircraft::getType(){
    return "base aircraft";
}

int Aircraft::getMaxAmmo(){
    return maxAmmo;
}

int Aircraft::getCurrentAmmo()
{
    return currentAmmo;
}

int Aircraft::getDamage(){
    return currentAmmo * baseDamage;
}

int Aircraft::fight()
{
    int damage = baseDamage * currentAmmo;
    currentAmmo = 0;
    return damage;
}



int Aircraft::refill(int ammoAmount)
{
    int diff = maxAmmo - currentAmmo;
    currentAmmo = maxAmmo;
    return ammoAmount - diff;
}

bool Aircraft::isPriority(){
    return priority;
}

std::string Aircraft::getStatus()
{
    return "Type " + type + ", Ammo: " + std::to_string(currentAmmo) + ", Base Damage: " + std::to_string(baseDamage)
                        + ", All Damage: " + std::to_string(getDamage()) + "\n";
}