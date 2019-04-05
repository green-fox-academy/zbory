#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%
    // %%  %
    // % % %
    // %  %%
    // %%%%%
    //
    // The square should have as many lines as the number was
    int side_len;
    std::cout << "Please input the side lenght:";
    std::cin >> side_len;

    for (int i = 0; i < side_len; i++) {
        std::cout << "$";
    }

    std::cout << std::endl;

    for (int i = 0; i < side_len - 2; i++) {
        for (int j = 0; j < side_len; j++) {
            if (j == 0 || j == side_len - 1 || j == i + 1)
                std::cout << "$";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < side_len; i++) {
        std::cout << "$";
    }

    return 0;
}