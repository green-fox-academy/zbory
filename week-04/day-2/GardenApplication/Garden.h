//
// Created by zbora on 2019-04-23.
//

#ifndef GARDENAPPLICATION_GARDEN_H
#define GARDENAPPLICATION_GARDEN_H

#include "Plant.h"

class Garden {
public:
    void addPlant(Plant *plant);
    void waterPlants(int waterAmount);
    void printGardenState();
private:
    std::vector<Plant*> plants;
};


#endif //GARDENAPPLICATION_GARDEN_H
