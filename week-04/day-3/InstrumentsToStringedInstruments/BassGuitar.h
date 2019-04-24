//
// Created by zbora on 2019-04-24.
//

#ifndef INSTRUMENTSTOSTRINGEDINSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTSTOSTRINGEDINSTRUMENTS_BASSGUITAR_H


#include "StringedInstrument.h"

class BassGuitar : public StringedInstrument{
public:
    BassGuitar();

    BassGuitar(int strings);

    std::string sound() override;

};


#endif //INSTRUMENTSTOSTRINGEDINSTRUMENTS_BASSGUITAR_H
