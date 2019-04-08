#include <iostream>

int askAmount();
int askNumbers(int numbers[], int amount);
int findMax(int numbers[], int amount);

int main() {
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    int amount = askAmount();
    int numbers[amount];

    askNumbers(numbers, amount);

    int maxIndex = findMax(numbers, amount);
    
    std::cout << "max value: " << numbers[maxIndex] << ", address: " << &numbers[maxIndex];
    return 0;
}

int askAmount() {
    int amount;
    std::cout << "How many numbers do you want to work with?" << std::endl;
    std::cin >> amount;
    return amount;
}
int askNumbers(int numbers[], int amount){
    for (int i = 0; i < amount; i++) {
        std::cout << i + 1 << ". number:";
        std::cin >> numbers[i];
    }
}
int findMax(int numbers[], int amount){
    int maxIndex = 0;
    for (int i = 0; i < amount; i++) {
        if (numbers[i] > numbers[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}