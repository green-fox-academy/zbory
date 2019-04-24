//
// Created by zbora on 2019-04-24.
//

#include <iostream>
#include "wirelessAdapter.h"


WirelessAdapter::WirelessAdapter(std::string id, std::string usbType, int bandwidth) : Device(id), USBDevice(id, usbType), NetworkDevice(id, bandwidth)
{}

void WirelessAdapter::info()
{
    std::cout << "id: " << id << ", USB type: " << usbType << ", bandwidth: " << bandwidth;
}