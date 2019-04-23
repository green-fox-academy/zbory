//
// Created by zbora on 2019-04-23.
//

#include <iostream>
#include "Tree.h"


Tree::Tree(std::string color) :Plant(color, "Tree")
{}

bool Tree::needsWater()
{
    if (waterLevel < 10)
        return true;
    else
        return false;
}

void Tree::toWater(double waterAmount)
{
    waterLevel += 0.4 * waterAmount;
}