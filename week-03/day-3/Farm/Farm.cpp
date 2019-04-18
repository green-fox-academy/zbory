//
// Created by zbora on 2019-04-18.
//

#include "Farm.h"

Farm::Farm(int slots){
    this->slots = slots;
}

int Farm::getSlots(){
    return slots;
}

int Farm::getAnimalCount(){
    return animals.size();
}

Animal* Farm::getAnimal(int i){
    return &animals[i];
}

void Farm::addAnimal(Animal animal){
    if(slots > 0) {
        animals.push_back(animal);
        slots--;
    }else{
        std::cout << "The stable is full!";
    }
}

void Farm::breed()
{
    if (slots > 0) {
        animals.push_back(Animal());
        slots--;
    }else{
        std::cout << "The stable is full!";
    }
}

void Farm::moveToTheCity()
{
    int index = 0;
    int hunger = animals[index].getHunger();
    for (int i = 0; i < animals.size(); i++) {
        if(animals[i].getHunger() < hunger){
            index = i;
            hunger = animals[i].getHunger();
        }
    }
    animals.erase(animals.begin() + index);
    slots++;
}