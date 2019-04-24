//
// Created by zbora on 2019-04-24.
//

#include "StringedInstrument.h"
#include "Violin.h"

Violin::Violin() : StringedInstrument("Violin", 4)
{}

Violin::Violin(int string) :StringedInstrument("Violin", string)
{}

std::string Violin::sound()
{
    return "Screech";
}