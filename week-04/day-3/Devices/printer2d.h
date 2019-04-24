//
// Created by zbora on 2019-04-24.
//

#ifndef DEVICES_PRINTER2D_H
#define DEVICES_PRINTER2D_H


#include "printer.h"

class Printer2d : public Printer {
public:
    Printer2d(int sizeX, int sizeY);

    std::string getSize() override;

private:
    int sizeX;
    int sizeY;
};


#endif //DEVICES_PRINTER2D_H
