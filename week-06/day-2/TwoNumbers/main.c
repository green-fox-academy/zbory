#include<stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13
    int number1 = 22;
    int number2 = 13;

    // Print the result of 13 added to 22
    printf("add: %d\n", number1 + number2);
    // Print the result of 13 substracted from 22
    printf("substract: %d\n", number1 - number2);
    // Print the result of 22 multiplied by 13
    printf("multiply: %d\n", number1 * number2);
    // Print the result of 22 divided by 13 (as a decimal fraction)
    printf("divide: %.3f\n", (float)number1 / (float)number2);
    // Print the reminder of 22 divided by 13
    printf("remainder: %d\n", number1 % number2);
    // Store the results in variables and use them when you display the result

    return 0;
}