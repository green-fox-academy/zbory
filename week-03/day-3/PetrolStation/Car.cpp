//
// Created by zbora on 2019-04-17.
//

#include "Car.h"

Car::Car(std::string name, int gasAmount, int capacity)
{
    this->name = name;
    this->gasAmount = gasAmount;
    this->capacity = capacity;
}

std::string Car::getName()
{
    return name;
}

bool Car::isFull()
{
    return (gasAmount == capacity);
}

void Car::fill()
{
    gasAmount++;
}