#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    //
    // The diamond should have as many lines as the number was

    int num;
    int spaces;
    std::cout << "Please input a number:";
    std::cin >> num;
    spaces = num / 2 -1;


    for (int i = 0; i < num / 2; i++) {
        for (int j = 0; j < spaces; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            std::cout << "*";
        }
        spaces--;
        std::cout << std::endl;
    }

    spaces = 0;
    for (int i = 0; i < num / 2; i++) {
        for (int j = 0; j < spaces; j++) {
            std::cout << " ";
        }
        for (int j = i * 2 + 1; j > 0; j--) {
            std::cout << "*";
        }
        spaces++;
        std::cout << std::endl;
    }


    return 0;
}