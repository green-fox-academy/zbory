//
// Created by zbora on 2019-04-24.
//

#include "printer2d.h"

Printer2d::Printer2d(int sizeX, int sizeY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

std::string Printer2d::getSize()
{
    return  std::to_string(sizeX) + " X " + std::to_string(sizeY);
}