//
// Created by zbora on 2019-04-24.
//

#ifndef INSTRUMENTSTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTSTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H


#include "Instrument.h"

class StringedInstrument : public Instrument {
public:
    StringedInstrument(std::string name, int strings);

    virtual std::string sound() = 0;

    void play() override final;

protected:
    int numberOfStrings;
};


#endif //INSTRUMENTSTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H
