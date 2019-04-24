//
// Created by zbora on 2019-04-24.
//

#ifndef WIRELESSADAPTER_NETWORKDEVICE_H
#define WIRELESSADAPTER_NETWORKDEVICE_H

#include "device.h"

class NetworkDevice : virtual public Device {
public:
    NetworkDevice(std::string id, int bandwidth);

protected:
    int bandwidth;
};


#endif //WIRELESSADAPTER_NETWORKDEVICE_H
