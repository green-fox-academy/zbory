//
// Created by zbora on 2019-04-24.
//

#include <iostream>
#include "mammals.h"

Mammal::Mammal(std::string name) :BreedByLive(name)
{}

std::string Mammal::feed()
{
    return "I eat meat, plants and everything inbetween...nom nomnom...";
}

std::string Mammal::hunt()
{
    return "I hunt by being smart!";
}