//
// Created by zbora on 2019-04-23.
//

#include <stdexcept>
#include <iostream>
#include "Carrier.h"
#include "F35.h"
#include "F16.h"

Carrier::Carrier(int health, int initialAmmo)
{
    this->health = health;
    storedAmmo = initialAmmo;
}

void Carrier::addAircraft(Aircraft *aircraft)
{
    aircrafts.push_back(aircraft);
}

int Carrier::getHealth()
{
    return health;
}

void Carrier::setHealth(int newHealth){
    health = newHealth;
}

void Carrier::fill()
{
    if (storedAmmo == 0)
        throw std::runtime_error("No ammo");

    int neededAmmo = 0;
    for (int i = 0; i < aircrafts.size(); ++i) {
        neededAmmo += aircrafts[i]->getMaxAmmo() - aircrafts[i]->getCurrentAmmo();
    }

    if (neededAmmo > storedAmmo) {
        for (int j = 0; j < aircrafts.size(); ++j) {
            if (aircrafts[j]->isPriority()) {
                storedAmmo = aircrafts[j]->refill(storedAmmo);
            }
        }
    } else {
        for (int j = 0; j < aircrafts.size(); ++j) {
            storedAmmo = aircrafts[j]->refill(storedAmmo);
        }
    }
}

void Carrier::fight(Carrier &enemy)
{
    int damage = 0;

    for (int i = 0; i < aircrafts.size(); ++i) {
        damage += aircrafts[i]->fight();
    }

    enemy.setHealth(enemy.getHealth()-damage);
}

void Carrier::getCarrierStatus()
{
    if(health < 0) {
        std::cout << "\nIt's dead Jim :(\n";
        return;
    }
    int damage = 0;

    for (int i = 0; i < aircrafts.size(); ++i) {
        damage += aircrafts[i]->getDamage();
    }

    std::string status = "HP:" + std::to_string(health) + ", Aircraft count: " + std::to_string(aircrafts.size())
            + ", Ammo storage: " + std::to_string(storedAmmo) + ", Total damage: " + std::to_string(damage)
            + "\nAircrafts:\n";

    std::cout << "\nCarrier status-------------------------------------\n";
    std::cout << status;
    for (int i = 0; i < aircrafts.size(); ++i) {
        std::cout << aircrafts[i]->getStatus();
    }
}

