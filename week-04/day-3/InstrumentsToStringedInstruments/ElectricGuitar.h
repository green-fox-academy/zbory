//
// Created by zbora on 2019-04-24.
//

#ifndef INSTRUMENTSTOSTRINGEDINSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTSTOSTRINGEDINSTRUMENTS_ELECTRICGUITAR_H


#include "StringedInstrument.h"

class ElectricGuitar : public StringedInstrument {
public:
    ElectricGuitar();
    ElectricGuitar(int strings);
    std::string sound() override;
};


#endif //INSTRUMENTSTOSTRINGEDINSTRUMENTS_ELECTRICGUITAR_H
