//
// Created by zbora on 2019-04-23.
//

#ifndef AIRCRAFTCARRIER_CARRIER_H
#define AIRCRAFTCARRIER_CARRIER_H


#include <vector>
#include "Aircraft.h"

class Carrier {
public:
    Carrier(int health, int initialAmmo);
    int getHealth();
    void setHealth(int newHealth);
    void addAircraft(Aircraft* aircraft);
    void fill();
    void fight(Carrier &enemy);
    void getCarrierStatus();
private:
    std::vector<Aircraft*> aircrafts;
    int storedAmmo;
    int health;
};


#endif //AIRCRAFTCARRIER_CARRIER_H
