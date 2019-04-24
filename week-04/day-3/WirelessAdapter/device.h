//
// Created by zbora on 2019-04-24.
//

#ifndef WIRELESSADAPTER_DEVICE_H
#define WIRELESSADAPTER_DEVICE_H


#include <string>

class Device {
public:
    Device(std::string id);
    std::string getId();
protected:
    std::string id;

};


#endif //WIRELESSADAPTER_DEVICE_H
