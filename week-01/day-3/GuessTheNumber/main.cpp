#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    int number = 14;
    int guess;
    bool guessed = false;

    std::cout << "Wait...OK, I got the number! Guess!" << std::endl;

    do {
        std::cin >> guess;

        if (guess == number) {
            std::cout << "Congrats! You are a mind reader!" << std::endl;
            guessed = true;
        } else if (guess > number) {
            std::cout << "My number is smaller, guess again!" << std::endl;
        } else {
            std::cout << "My number is bigger, guess again!" << std::endl;
        }

    } while (!guessed);

    return 0;
}