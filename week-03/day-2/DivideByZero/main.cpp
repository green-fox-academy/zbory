#include <iostream>
#include <fstream>

void divide(int number);

int main() {
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0

    int number;
    std::cout << "Please input a divisor:";
    std::cin >> number;

    try{
        divide(number);
    }catch(std::runtime_error e){
        std::cout << e.what();
    }

    return 0;
}

void divide(int number){
    if(number == 0){
        throw std::runtime_error("fail");
    }
    std::cout << 10 / number;
}