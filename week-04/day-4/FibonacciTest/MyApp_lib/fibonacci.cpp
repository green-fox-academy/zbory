//
// Created by zbora on 2019-04-25.
//


int fibonacci(int number)
{
    if (number == 1) return 1;
    if (number == 0) return 0;

    return fibonacci(number - 1) + fibonacci(number - 2);
}