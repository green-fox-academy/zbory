//
// Created by zbora on 2019-04-24.
//

#ifndef ANIMALSINTHEZOO_BREEDBYLIVE_H
#define ANIMALSINTHEZOO_BREEDBYLIVE_H


#include "animal.h"

class BreedByLive : public Animal {
public:
    BreedByLive(std::string name);

    std::string breed() override final;

};


#endif //ANIMALSINTHEZOO_BREEDBYLIVE_H
