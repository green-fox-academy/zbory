//
// Created by zbora on 2019-04-24.
//

#ifndef ANIMALSINTHEZOO_BIRD_H
#define ANIMALSINTHEZOO_BIRD_H

#include <iostream>
#include "breedByEgg.h"

class Bird : public BreedByEgg {
public:
    Bird(std::string name);

    std::string feed() override;
    std::string hunt() override;
};


#endif //ANIMALSINTHEZOO_BIRD_H
