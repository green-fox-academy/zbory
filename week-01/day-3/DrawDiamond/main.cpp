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


    //Need to handle spaces differently in odd and even cases
    //The whole image also needs to be shifted 1 space from the left side
    spaces = (num % 2) ? num / 2 + 1 : num / 2;
    int top_levels = num / 2;

    for (int i = 0; i < top_levels; i++) {
        for (int j = 0; j < spaces; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            std::cout << "*";
        }
        spaces--;
        std::cout << std::endl;
    }

    //Need to handle halving level in odd even cases differently
    //Odd: half + 1 bottom levels, Even: half bottom levels
    int bottom_levels = (num % 2) ? num / 2 + 1 : num / 2;
    for (int i = 0; i < bottom_levels; i++) {
        for (int j = 0; j < i + 1; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < (bottom_levels - i) * 2 - 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }


    return 0;
}