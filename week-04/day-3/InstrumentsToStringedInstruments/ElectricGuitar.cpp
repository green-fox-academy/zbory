
#include "ElectricGuitar.h"

ElectricGuitar::ElectricGuitar() :StringedInstrument("Electric Guitar", 6){}

ElectricGuitar::ElectricGuitar(int strings) :StringedInstrument("Electric Guitar", strings)
{

}

std::string ElectricGuitar::sound()
{
    return "Twang";
}