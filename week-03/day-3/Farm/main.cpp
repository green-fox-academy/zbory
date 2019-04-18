#include <iostream>
#include "Farm.h"
#include "Animal.h"

int main()
{
    Farm farm(10);
    std::cout << "Slots: " << farm.getSlots() << std::endl;

    farm.breed();
    farm.breed();
    farm.breed();
    farm.getAnimal(0)->eat();
    farm.getAnimal(0)->eat();
    farm.getAnimal(0)->eat();

    for (int i = 0; i < farm.getAnimalCount(); ++i) {
        std::cout << farm.getAnimal(i)->getHunger() << std::endl;
    }

    std::cout << "Slots: " << farm.getSlots() << std::endl;

    farm.moveToTheCity();

    for (int i = 0; i < farm.getAnimalCount(); ++i) {
        std::cout << farm.getAnimal(i)->getHunger() << std::endl;
    }

    std::cout << "Slots: " << farm.getSlots() << std::endl;
    return 0;
}