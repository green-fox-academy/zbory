#include <iostream>
#include <string>

int main(int argc, char *args[]) {

    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output

    int user_input = 0;
    int size_parameter = 5;

    std::cout << "Please input the size (if you want the default press 0):";
    std::cin >> user_input;

    if (user_input != 0) {
        size_parameter = user_input;
    }

    for (int i = 0; i < size_parameter; i++) {
        for (int j = 0; j < size_parameter; j++) {
            if (i == j){
                std::cout << "1";
            }else{
                std::cout << "0";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}