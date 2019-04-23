//
// Created by zbora on 2019-04-23.
//

#include <iostream>
#include "Flower.h"


Flower::Flower(std::string color) : Plant(color,"Flower")
{}

bool Flower::needsWater()
{
    if (waterLevel < 5)
        return true;
    else
        return false;
}

void Flower::toWater(double waterAmount)
{
    waterLevel += 0.75 * waterAmount;
}