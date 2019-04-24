//
// Created by zbora on 2019-04-24.
//

#include <iostream>
#include "BassGuitar.h"
#include "StringedInstrument.h"


BassGuitar::BassGuitar() :StringedInstrument("Bass Guitar", 4)
{}

BassGuitar::BassGuitar(int string) :StringedInstrument("Bass Guitar", string)
{}

std::string BassGuitar::sound(){
    return "Duum-duum-duum";
}