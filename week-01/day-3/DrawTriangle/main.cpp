#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:
    //
    // *
    // **
    // ***
    // ****
    //
    // The triangle should have as many lines as the number was

    int num;
    std::cout << "Please input a number: ";
    std::cin >> num;

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < i + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }


    return 0;
}