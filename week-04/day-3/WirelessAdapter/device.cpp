//
// Created by zbora on 2019-04-24.
//

#include "device.h"


Device::Device(std::string id)
{
    this->id = id;
}

std::string Device::getId()
{
    return id;
}
