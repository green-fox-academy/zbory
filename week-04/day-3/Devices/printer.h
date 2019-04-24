//
// Created by zbora on 2019-04-24.
//

#ifndef DEVICES_PRINTER_H
#define DEVICES_PRINTER_H


#include <string>

class Printer {
public:
    virtual std::string getSize()=0;
    void print();
};


#endif //DEVICES_PRINTER_H
