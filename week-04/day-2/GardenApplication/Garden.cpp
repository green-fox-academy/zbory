//
// Created by zbora on 2019-04-23.
//

#include <iostream>
#include <vector>
#include "Garden.h"

void Garden::addPlant(Plant *plant)
{
    plants.push_back(plant);
}

void Garden::waterPlants(int waterAmount)
{
    std::cout << "Watering plants with " << waterAmount << std::endl;
    int count = 0;
    for (int i = 0; i < plants.size(); ++i) {
        if(plants[i]->needsWater())
            count++;
    }
    for (int j = 0; j < plants.size(); ++j) {
        plants[j]->toWater(waterAmount / (double)count);
    }
}

void Garden::printGardenState()
{
    for (int i = 0; i < plants.size(); ++i) {
        plants[i]->printPlantState();
    }
}