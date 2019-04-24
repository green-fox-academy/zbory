//
// Created by zbora on 2019-04-24.
//

#ifndef WIRELESSADAPTER_USBDEVICE_H
#define WIRELESSADAPTER_USBDEVICE_H

#include "device.h"

class USBDevice :virtual public Device{
public:
    USBDevice(std::string id, std::string usbType);

protected:
    std::string usbType;
};


#endif //WIRELESSADAPTER_USBDEVICE_H
