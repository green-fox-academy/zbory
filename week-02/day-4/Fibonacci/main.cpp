#include <iostream>

int fibonacci(int number);

int main()
{
    int nth_number = 30;
//    std::cout << "The number of the Fibonacci number you want: ";
//    std::cin >> nth_number;

    std::cout << fibonacci(nth_number) << std::endl;
    return 0;
}

int fibonacci(int number)
{
    if (number == 1) return 1;
    if (number == 0) return 0;

    return fibonacci(number - 1) + fibonacci(number - 2);
}