#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    int number = rand() % 100 + 1;
    int guessed_number;

    printf("I thought of a number between 1 and a 100.\nGuess!\n");
    do{
        scanf("%d", &guessed_number);
        if(number >guessed_number)
            printf("The stored number is higher!\n");
        else
            printf("The stored number is lower!\n");
    }while(number != guessed_number);
    printf("Congrats! I thought of %d", number);
    return 0;
}