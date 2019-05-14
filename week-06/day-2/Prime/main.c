#include <stdio.h>
#include <stdlib.h>

int is_prime(int number);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    int number;
    printf("Please input a number!\n");
    scanf("%d", &number);

    printf("This number is %s number!\n", is_prime(number) ? "a prime" : "not a prime");

    return 0;
}

int is_prime(int number)
{
    int result = 1;
    for (int i = 0; i < number / 2; ++i) {
        if (!(number % (i + 2)))
            result = 0;
    }
    return result;
}