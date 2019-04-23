//
// Created by zbora on 2019-04-23.
//

#ifndef GARDENAPPLICATION_TREE_H
#define GARDENAPPLICATION_TREE_H


#include "Plant.h"

class Tree : public Plant {
public:
    Tree(std::string color);

    bool needsWater() override;

    void toWater(double waterAmount) override;
};


#endif //GARDENAPPLICATION_TREE_H
