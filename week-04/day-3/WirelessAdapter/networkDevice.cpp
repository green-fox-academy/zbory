//
// Created by zbora on 2019-04-24.
//

#include <iostream>
#include "networkDevice.h"

NetworkDevice::NetworkDevice(std::string id, int bandwidth) :Device(id)
{
    this->bandwidth = bandwidth;
}

