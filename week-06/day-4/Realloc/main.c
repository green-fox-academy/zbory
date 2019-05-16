#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int numberX;
    printf("Please input a number!\n");
    scanf("%d", &numberX);

    int *arrayX = malloc(sizeof(int) * numberX);
    int sum = 0;

    printf("OK, lets do this.. ");
    for (int i = 0; i < numberX; ++i) {
        printf("%d. number:", i + 1);
        scanf("%d", &arrayX[i]);
        sum += arrayX[i];
    }

    int *Tibet = (int *) malloc(sizeof(int) * sum);
    for (int j = 0; j < sum; ++j) {
        Tibet[j] = j + 1;
        printf("%d ", Tibet[j]);
    }

    free(arrayX);
    free(Tibet);
    return 0;
}