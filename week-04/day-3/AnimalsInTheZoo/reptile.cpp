//
// Created by zbora on 2019-04-24.
//

#include <iostream>
#include "reptile.h"

Reptile::Reptile(std::string name) :BreedByEgg(name)
{}

std::string Reptile::feed()
{
    return "My favourite food is meat and insects... (zzzzz) ...What was that?!";
}

std::string Reptile::hunt()
{
    return "I hunt from hiding";
}