#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that prints the numbers from 1 to 100.
    // But for multiples of three print “Fizz” instead of the number
    // and for the multiples of five print “Buzz”.
    // For numbers which are multiples of both three and five print “FizzBuzz”.

    for (int i = 1; i <= 100; i++) {
        if ((i % 3) == 0)
            if ((i % 5) == 0)
                std::cout << "FizzBuzz" << std::endl;
            else
                std::cout << "Fizz" << std::endl;
        else if ((i % 5) == 0)
            std::cout << "Buzz" << std::endl;
        std::cout << i << std::endl;
    }

    return 0;
}