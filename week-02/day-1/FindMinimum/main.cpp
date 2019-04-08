#include <iostream>

int *minimumValue(int list[], int size);

int main() {
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15, 2, 1};

    int size = sizeof(numbers) / sizeof(numbers[0]);
    int *min = minimumValue(numbers,size);

    std::cout << *min;

    return 0;
}

int *minimumValue(int list[], int size) {
    int minIndex = 0;
    for (int i = 0; i < size; i++){
        if(list[minIndex] > list[i])
            minIndex = i;
    }
    return &list[minIndex];
}