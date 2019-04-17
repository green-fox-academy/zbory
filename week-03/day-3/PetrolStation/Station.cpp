//
// Created by zbora on 2019-04-17.
//

#include "Station.h"

Station::Station(int gasAmount)
{
    this->gasAmount = gasAmount;
}

void Station::fill(Car car)
{
    while(!car.isFull()) {
        car.fill();
        gasAmount--;
        std::cout << "Filling " << car.getName() << std::endl;
    }
    std::cout << "Remaining amount of gas: " << gasAmount <<std::endl;
}