#include <iostream>
#include "Animal.h"

int main()
{
    Animal animal;

    animal.play();
    animal.drink();
    std::cout << "hunger: " << animal.getHunger() << ", thirst: " << animal.getThirst() << std::endl;
    return 0;
}