#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have
    int chickens;
    int pigs;

    std::cout << "Please input the number of chickens: " << std::endl;
    std::cin >> chickens;
    std::cout << "Please input the number of pigs: " << std::endl;
    std::cin >> pigs;
    std::cout << "The total number of legs equals: " << 2 * chickens + 4 * pigs;

    return 0;
}