#include <iostream>

int foundItem(int numbers[], int size, int lookFor);

int main() {
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1

    int numbers[] = {1, 4, 6, 34, 6, 345, 87};
    int toFind = 99;
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int result = foundItem(numbers, size, toFind);
    if (result < 0) {
        std::cout << "The item is not in the array!";
    }else{
        std::cout << "The item is at the " << result <<". position.";
    }


    return 0;
}

int foundItem(int numbers[], int size, int lookFor) {
    for (int i = 0; i < size; i++) {
        if (numbers[i] == lookFor) {
            return i;
        }

    }
    return -1;
}