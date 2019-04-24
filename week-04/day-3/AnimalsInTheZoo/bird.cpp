//
// Created by zbora on 2019-04-24.
//

#include "bird.h"

Bird::Bird(std::string name) :BreedByEgg(name)
{}

std::string Bird::feed()
{
    return "I like all kinds of stuff; meat, plants, insects";
}

std::string Bird::hunt()
{
    return "I hunt by flying fast!";
}