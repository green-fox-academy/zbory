//
// Created by zbora on 2019-04-24.
//

#include <iostream>
#include "copier.h"

Copier::Copier(int sizeX, int sizeY, int speed) :Printer2d(sizeX,sizeY), Scanner(speed)
{}

void Copier::copy()
{
    scan();
    std::cout << " and ";
    print();

}