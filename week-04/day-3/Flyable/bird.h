//
// Created by zbora on 2019-04-24.
//

#ifndef FLYABLE_BIRD_H
#define FLYABLE_BIRD_H


#include <string>
#include "Flyable.h"

class Bird :public Flyable{
public:
    Bird(std::string kind);

    void land() override;

    void fly() override;

    void takeOff() override;

private:
    std::string kind;
};


#endif //FLYABLE_BIRD_H
