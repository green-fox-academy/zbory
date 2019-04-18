//
// Created by zbora on 2019-04-18.
//

#ifndef FARM_FARM_H
#define FARM_FARM_H

#include <iostream>
#include <vector>
#include "Animal.h"

class Farm {
public:
    Farm(int slots);
    int getSlots();
    int getAnimalCount();
    void addAnimal(Animal animal);
    void breed();
    void moveToTheCity();
    Animal* getAnimal(int i);
private:
    std::vector<Animal> animals;
    int slots;
};


#endif //FARM_FARM_H
