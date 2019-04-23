//
// Created by zbora on 2019-04-23.
//

#include <iostream>
#include "Plant.h"


Plant::Plant(std::string color, std::string type)
{
    this->color = color;
    this->type = type;
    waterLevel = 0;
}

double Plant::getWaterLevel()
{
    return waterLevel;
}

bool Plant::needsWater()
{
    return true;
}

void Plant::toWater(double waterAmount)
{
    waterLevel += waterAmount;
}

void Plant::printPlantState()
{
    std::cout << "The " << color <<  " " << type << (needsWater() ? " needs " : " doesn't need ") << "water.\n";
}