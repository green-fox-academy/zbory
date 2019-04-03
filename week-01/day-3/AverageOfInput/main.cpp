#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4

    int temp = 0;
    int sum = 0;

    for(int i = 0; i < 5; i++){
        std::cout << "Please input the " << i + 1 <<". number: ";
        std::cin >> temp;
        sum +=temp;
    }

    std::cout << "The average of these numbers is: " << sum / 5;

    return 0;
}