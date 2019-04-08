#include <iostream>

int main() {

    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    int numbers[5];

    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << ". number:";
        std::cin >> numbers[i];
    }

    int *numberPointer = numbers;

    std::cout << std::endl << "Values:\n";

    for (int i = 0; i < 5; i++) {
        std::cout << *(numberPointer + i) << std::endl;
    }

    return 0;
}