#include <stdio.h>
#include <stdlib.h>

int sum_of_digits(int number);

int equal_sum_of_digits(int number1, int number2);

int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    int num1;
    int num2;
    printf("Please input two numbers!\n");
    scanf("%d %d", &num1, &num2);

    printf("The sums of the digits of these numbers are %s!", equal_sum_of_digits(num1, num2) ? "equal" : "not equal");

    return 0;
}

int equal_sum_of_digits(int number1, int number2)
{
    return sum_of_digits(number1) == sum_of_digits(number2);
}

int sum_of_digits(int number)
{
    int sum = 0;

    do {
        sum += number % 10;
        number /= 10;
    } while (number != 0);
    return sum;
}