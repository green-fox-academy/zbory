//
// Created by zbora on 2019-04-23.
//

#ifndef GARDENAPPLICATION_FLOWER_H
#define GARDENAPPLICATION_FLOWER_H


#include "Plant.h"

class Flower : public Plant {
public:
    Flower(std::string color);

    bool needsWater() override;

    void toWater(double waterAmount) override;
};


#endif //GARDENAPPLICATION_FLOWER_H
