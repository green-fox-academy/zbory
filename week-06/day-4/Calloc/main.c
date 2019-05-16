#include <stdio.h>
#include <stdlib.h>

// with calloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits
// what's the difference between this and the previous excersice?

int main()
{
    int array_size = 10;
    int* pointer = NULL;

    pointer = (int*)calloc(sizeof(int), array_size);
    for (int i = 0; i < 5; ++i) {
        pointer[i] = i;
    }
    for (int j = 0; j < array_size; ++j) {
        printf("%d\n", pointer[j]);
    }

    return 0;
}