#include <iostream>

int main() {
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    int amount;
    std::cout << "How many numbers do you want to work with?" << std::endl;
    std::cin >> amount;

    int numbers[amount];

    for (int i = 0; i < amount; i++) {
        std::cout << i + 1 << ". number:";
        std::cin >> numbers[i];
    }

    int maxIndex = 0;
    for (int i = 0; i < amount; i++) {
        if (numbers[i] > numbers[maxIndex]){
            maxIndex = i;
        }
    }

    std::cout << "max value: " << numbers[maxIndex] << ", address: " << &numbers[maxIndex];
    return 0;
}