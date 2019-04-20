//
// Created by zbora on 2019-04-18.
//

#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H

#include "Pirate.h"


class Ship {
public:
    Ship();
    Ship(std::string name);
    std::string getName();
    Pirate *getPirate(int i);
    Pirate *getCaptain();
    void fillShip();
    void printCrewState();
    int countAlive();
    int countDead();
    int countPassedOut();
    bool battle(Ship &enemy);
    void party();

private:
    std::string name;
    Pirate captain;
    std::vector<Pirate> crew;
    int maxCrewSize;
};


#endif //PIRATES_SHIP_H
