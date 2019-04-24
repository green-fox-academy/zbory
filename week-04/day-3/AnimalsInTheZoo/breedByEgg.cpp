//
// Created by zbora on 2019-04-24.
//

#include "breedByEgg.h"

BreedByEgg::BreedByEgg(std::string name) :Animal(name)
{

}

std::string BreedByEgg::breed()
{
    return "laying eggs";
}