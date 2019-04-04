#include <iostream>
#include <string>

//  Create a function that takes a list of numbers as parameter
//  Don't forget you have to pass the size of the list as a parameter as well
//  Returns a list where the elements are sorted in ascending numerical order by using bubble sort
//  Make a second boolean parameter, if it's `true` sort that list descending

void bubbleSort(int list[], int size, bool ascending);

int main(int argc, char *args[]) {
    int list[] = {3, 10, 4, 65, 76, 43, 21};

    int size = sizeof(list) / sizeof(list[0]);

    for (int i = 0; i < size; i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    bubbleSort(list, size, false);

    for (int i = 0; i < size; i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void bubbleSort(int list[], int size, bool ascending) {
    if (ascending) {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (list[i] > list[j]) {
                    int temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (list[i] < list[j]) {
                    int temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    }
}