//
// Created by zbora on 2019-04-17.
//
#include "Animal.h"

Animal::Animal(){
    this->hunger = 50;
    this->thirst = 50;
}

Animal::Animal(int hunger, int thirst)
{
    this->hunger = hunger;
    this->thirst = thirst;
}

void Animal::eat()
{
    hunger--;
}

void Animal::drink()
{
    thirst--;
}

void Animal::play()
{
    hunger++;
    thirst++;
}

int Animal::getHunger() const
{
    return hunger;
}

int Animal::getThirst() const
{
    return thirst;
}
