#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was
    int num;
    int spaces;
    std::cout << "Please input a number:";
    std::cin >> num;
    spaces = num - 1;

    //std::cout << std::endl;

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < spaces; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            std::cout << "*";
        }
        spaces--;
        std::cout << std::endl;
    }


    return 0;
}