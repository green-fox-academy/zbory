//
// Created by zbora on 2019-04-24.
//

#ifndef ANIMALSINTHEZOO_REPTILE_H
#define ANIMALSINTHEZOO_REPTILE_H


#include <string>
#include "breedByEgg.h"

class Reptile : public BreedByEgg {
public:
    Reptile(std::string name);

    std::string feed() override;

    std::string hunt() override;
};


#endif //ANIMALSINTHEZOO_REPTILE_H
