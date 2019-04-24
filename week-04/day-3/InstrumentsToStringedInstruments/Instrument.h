//
// Created by zbora on 2019-04-24.
//

#ifndef INSTRUMENTSTOSTRINGEDINSTRUMENTS_INSTRUMENT_H
#define INSTRUMENTSTOSTRINGEDINSTRUMENTS_INSTRUMENT_H


#include <string>

class Instrument {
public:
    Instrument(std::string name);
    virtual void play()=0;
protected:
    std::string name;

};


#endif //INSTRUMENTSTOSTRINGEDINSTRUMENTS_INSTRUMENT_H
