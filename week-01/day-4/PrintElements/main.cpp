#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `numbers`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print all the elements of `numbers`

    int numbers[] = {4, 5, 6, 7};

    int num_size = sizeof(numbers) / sizeof(numbers[0]);

    for(int i = 0; i < num_size; i++){
        std::cout << numbers[i] <<std::endl;
    }

    return 0;
}