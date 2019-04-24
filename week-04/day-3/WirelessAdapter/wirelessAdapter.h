//
// Created by zbora on 2019-04-24.
//

#ifndef WIRELESSADAPTER_WIRELESSADAPTER_H
#define WIRELESSADAPTER_WIRELESSADAPTER_H

#include "USBDevice.h"
#include "networkDevice.h"

class WirelessAdapter :public USBDevice, public NetworkDevice{
public:
    WirelessAdapter(std::string id, std::string usbType, int bandwidth);
    void info();
};


#endif //WIRELESSADAPTER_WIRELESSADAPTER_H
