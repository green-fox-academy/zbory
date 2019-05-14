#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    int number;

    printf("Please input a number!\n");
    scanf("%d", &number);
    printf("The nunber is %s!", number % 2 ? "odd" : "even");

    return 0;
}