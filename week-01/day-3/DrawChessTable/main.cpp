#include <iostream>

int main(int argc, char *args[]) {

    // Crate a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %

    int size = 8;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    std::cout << "%";
                } else {
                    std::cout << " ";
                }
            } else {
                    if (j % 2 == 0) {
                        std::cout << " ";
                    } else {
                        std::cout << "%";
                    }
                }
        }
        std::cout << std::endl;
    }

    return 0;
}