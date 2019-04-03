#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one
    int a;
    int b;

    std::cout << "Please input the first number: ";
    std::cin >> a;
    std::cout << "Please input the second number: ";
    std::cin >> b;

    std::cout << "The bigger of the two is: " << (a > b ? a: b);

    return 0;
}