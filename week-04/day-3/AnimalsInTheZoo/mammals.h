//
// Created by zbora on 2019-04-24.
//

#ifndef ANIMALSINTHEZOO_MAMMALS_H
#define ANIMALSINTHEZOO_MAMMALS_H


#include "breedByLive.h"

class Mammal : public BreedByLive {
public:
    Mammal(std::string name);

    std::string feed() override;

    std::string hunt() override;
};


#endif //ANIMALSINTHEZOO_MAMMALS_H
