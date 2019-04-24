//
// Created by zbora on 2019-04-24.
//

#include "animal.h"


Animal::Animal(std::string name)
{
    this->name = name;
}

std::string Animal::getName()
{
    return name;
}