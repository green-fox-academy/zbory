//
// Created by zbora on 2019-04-24.
//

#include <iostream>
#include "Helicopter.h"

Helicopter::Helicopter(int maxAltitude, int maxSpeed, int maxRange) : Vehicle(maxAltitude, maxSpeed, maxRange)
{}

void Helicopter::fly()
{
    std::cout << "chakk-chackk-chak-chak, chak-a-chak-akk-chk-chk-chk\n";
}

void Helicopter::takeOff()
{
    std::cout << "whumpa-whumpa-whumpa-whumpa whup-whup-whup\n";
}

void Helicopter::land()
{
    std::cout << "whooop whoop whop thunk kabooooom\n";
}