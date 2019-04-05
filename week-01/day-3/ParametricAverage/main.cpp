#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4
    int question_number;
    int input;
    int sum = 0;

    std::cout << "How many numbers do you want to input?" << std::endl;
    std::cin >> question_number;

    for (int i = 0; i < question_number; i++) {
        std::cout << "PLease input the " << i + 1 << ". number:";
        std::cin >> input;
        sum += input;
    }

    std::cout << "Sum: " << sum << " Average: " << sum / (double)question_number;

    return 0;
}