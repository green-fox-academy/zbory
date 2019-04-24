//
// Created by zbora on 2019-04-24.
//

#include "printer3d.h"

Printer3d::Printer3d(int sizeX, int sizeY, int sizeZ)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->sizeZ = sizeZ;
}

std::string Printer3d::getSize()
{
    return std::to_string(sizeX) + " X " + std::to_string(sizeY) + " X " + std::to_string(sizeZ);
}