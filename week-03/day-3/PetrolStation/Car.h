//
// Created by zbora on 2019-04-17.
//

#ifndef PETROLSTATION_CAR_H
#define PETROLSTATION_CAR_H

#include <iostream>


class Car {
public:
    Car(std::string name, int gasAmount, int capacity);
    std::string getName();
    bool isFull();
    void fill();
private:
    int gasAmount;
    int capacity;
    std::string name;
};


#endif //PETROLSTATION_CAR_H
