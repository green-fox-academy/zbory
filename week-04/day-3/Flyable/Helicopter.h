//
// Created by zbora on 2019-04-24.
//

#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H


#include "Flyable.h"
#include "vehicle.h"

class Helicopter : public Flyable, public Vehicle {
public:
    Helicopter(int maxAltitude, int maxSpeed, int maxRange);

    void fly() override;

    void land() override;

    void takeOff() override;
};


#endif //FLYABLE_HELICOPTER_H
