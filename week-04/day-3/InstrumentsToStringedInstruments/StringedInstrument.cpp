//
// Created by zbora on 2019-04-24.
//

#include <iostream>
#include "StringedInstrument.h"

StringedInstrument::StringedInstrument(std::string name, int strings) : Instrument(name)
{
    numberOfStrings = strings;
}

void StringedInstrument::play()
{
    std::cout << name << ", a " << numberOfStrings << "-stringed instrument that goes " << sound() << std::endl;
}