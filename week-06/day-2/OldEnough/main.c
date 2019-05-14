#include <stdio.h>
#include <stdlib.h>

int old_enough(int age);

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    int age;
    printf("Please input your age!\n");
    scanf("%d", &age);

    if(old_enough(age))
        printf("Give him a bear!");
    else
        printf("It's fruit juice for him!");

    return 0;
}

int old_enough(int age)
{
    if (age >= 18)
        return 1;
    else
        return 0;
}