//
// Created by zbora on 2019-04-24.
//

#include <iostream>
#include "bird.h"


Bird::Bird(std::string kind)
{
    this->kind = kind;
}

void Bird::land()
{
    std::cout << "thump\n";
}

void Bird::fly()
{
    std::cout << "Is it a plane? Is it Superman? It is a bird!\n";
}

void Bird::takeOff()
{
    std::cout << "Houston we have lift-off\n";
}
