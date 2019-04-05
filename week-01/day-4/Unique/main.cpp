#include <iostream>
#include <string>

bool findInArray(int element, int array[], int size);

void unique(int list[], int size);


int main(int argc, char *args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};

    int size = sizeof(numbers) / sizeof(numbers[0]);

    unique(numbers, size);
    //std::cout << (unique(numbers)) << std::endl;
    //  should print: `[1, 11, 34, 52, 61]`

    return 0;
}


void unique(int list[], int size) {
    int result[size];
    int result_count = 0;

    for (int i = 0; i < size; i++) {
        if (!findInArray(list[i], result, size)) {
            result[i] = list[i];
            result_count++;
        }
    }

    for (int i = 0; i < result_count; i++) {
        std::cout << result[i] << " ";
    }

}

bool findInArray(int element, int array[], int size) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (element == array[i])
            found = true;
    }
    return found;
}

