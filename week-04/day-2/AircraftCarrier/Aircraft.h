//
// Created by zbora on 2019-04-23.
//

#ifndef AIRCRAFTCARRIER_AIRCRAFT_H
#define AIRCRAFTCARRIER_AIRCRAFT_H

#include <iostream>

class Aircraft {
public:
    Aircraft(int baseDamage, int maxAmmo);
    std::string getType();
    int getMaxAmmo();
    int getCurrentAmmo();
    int getDamage();
    int fight();
    int refill(int ammoAmount);
    bool isPriority();
    std::string getStatus();
protected:
    std::string type;
    bool priority;
    int currentAmmo;
    int maxAmmo;
    int baseDamage;
};


#endif //AIRCRAFTCARRIER_AIRCRAFT_H
