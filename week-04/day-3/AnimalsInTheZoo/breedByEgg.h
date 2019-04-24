//
// Created by zbora on 2019-04-24.
//

#ifndef ANIMALSINTHEZOO_BREEDBYEGG_H
#define ANIMALSINTHEZOO_BREEDBYEGG_H


#include "animal.h"

class BreedByEgg : public Animal {
public:
    BreedByEgg(std::string name);

    std::string breed() override final;
};


#endif //ANIMALSINTHEZOO_BREEDBYEGG_H
