#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The rich uncle has just died and you need to distribute his heritage among the relatives. The money you have to distribute is $1024
// Generate a random number between 20 and 50. This number will be the amount of relatives that showed up at the inheritance party.
// Allocate an array for them. Each element of the array will represent a relative.
// You need to generate a random number between 0 and the number of relatives to decide which one is the winner.
// The winner always gets the half of the remaining money. You need to generate random numbers until all the money is gone.
// Print the amount of money each relative got on the party. Print 0 for the unlucky ones.

//For example: 0,0,0,0,128,4,0,0,2,0,512,0,0,0,0,0,0,32,0,64,0,0,1,8,0,0,16,256

int main()
{
    srand(time(0));
    int money = 1024;
    int relatives = 20 + rand() % 31;
    int *values = (int *) calloc(sizeof(int), relatives);

    while (money != 0) {
        values[rand() % relatives] += money / 2;
        money /=2;
    }
    for (int i = 0; i < relatives; ++i) {
        printf("%d, ", values[i]);
    }

    return 0;
}