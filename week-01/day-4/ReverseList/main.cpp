#include <iostream>
#include <string>

int main(int argc, char *args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    int aj[] = {3, 4, 5, 6, 7, 8, 9};

    int size = sizeof(aj) / sizeof(aj[0]);

    for (int i = 0; i < size / 2; i++) {
        int temp = aj[i];
        aj[i] = aj[size - 1 - i];
        aj[size - 1 - i] = temp;
    }
    for(int i = 0; i < size; i++){
        std::cout << aj[i] << std::endl;
    }

    return 0;
}