#include <iostream>
#include <vector>
#include "Garden.h"
#include "Flower.h"
#include "Tree.h"

int main()
{
    Flower flower1("yellow");
    Flower flower2("blue");

    Tree tree1("purple");
    Tree tree2("orange");

    Garden garden;
    garden.addPlant(&flower1);
    garden.addPlant(&flower2);
    garden.addPlant(&tree1);
    garden.addPlant(&tree2);


    garden.printGardenState();
    std::cout << std::endl;

    garden.waterPlants(40);
    garden.printGardenState();
    std::cout << std::endl;

    garden.waterPlants(70);
    garden.printGardenState();

    return 0;
}