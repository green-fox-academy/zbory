//
// Created by zbora on 2019-04-24.
//

#include "USBDevice.h"

USBDevice::USBDevice(std::string id, std::string usbType) :Device(id)
{
    this->usbType = usbType;
}
