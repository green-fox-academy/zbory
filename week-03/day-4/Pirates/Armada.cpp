//
// Created by zbora on 2019-04-18.
//

#include <iostream>
#include "Armada.h"

Armada::Armada()
{
    maxArmadaSize = 2;
    fillArmada();
}

void Armada::fillArmada()
{
//    int crewCount = rand() % maxArmadaSize;
    for (int i = 0; i < maxArmadaSize; ++i) {
        ships.push_back(Ship());
    }
}

bool Armada::war(Armada &armada)
{
    int rounds = this->ships.size() > armada.ships.size() ? armada.ships.size() : this->ships.size();

    int i = 0;
    int j = 0;
    while (armada.ships[j].countAlive() > 0 && this->ships[i].countAlive() > 0) {
        this->ships[i].battle(armada.ships[j]);
        this->ships[i].printCrewState();
        armada.ships[j].printCrewState();

        if (armada.ships[j].countAlive() == 0) {
            std::cout << std::endl << armada.ships[j].getName() << " is now a wreck on the ocean bed.";
            j++;
            //If j got to the end of the enemy aramada
            if (j == armada.ships.size()) {
                std::cout << "\nWe showed them whose BOSS!";
                return true;
            }
        }
        if (this->ships[i].countAlive() == 0) {
            std::cout << std::endl << ships[i].getName() << " is now a wreck on the ocean bed.";
            i++;
            //If i got to the end of this armada
            if (i == this->ships.size()) {
                std::cout << "\nThe enemy has kicked our asses...";
                return false;
            }
        }
    }


}