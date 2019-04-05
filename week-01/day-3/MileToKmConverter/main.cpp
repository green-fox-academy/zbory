#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it
    int kilometer;

    std::cout << "Please input the distance in kilometers: " << std::endl;
    std::cin >> kilometer;
    std::cout << "The distance in miles is " << kilometer / 1.61 << "." << std::endl;

    return 0;
}