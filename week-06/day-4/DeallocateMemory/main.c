#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int array_size = 10;
    int *pointer = NULL;
    pointer = (int *) malloc(sizeof(int) * array_size);

    for (int i = 0; i < 10; ++i) {
        pointer[i] = 2 * i + 1;
    }

    for (int j = 0; j < 10; ++j) {
        printf("%d\n", pointer[j]);
    }

    //Undefined behaviour in C11
    pointer = realloc(pointer, 0);
    return 0;
}