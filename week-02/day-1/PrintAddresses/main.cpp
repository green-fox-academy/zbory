#include <iostream>

int main() {
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

    int numbers[5];

    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << ". number:";
        std::cin >> numbers[i];
    }

    std::cout << std::endl << "Addresses:\n";

    for (int i = 0; i < 5; i++) {
        std::cout << &numbers[i] << std::endl;
    }

    return 0;
}