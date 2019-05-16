#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

void sort(int *array, int size);

int main()
{
    int array_size = 10;
    int *even_array = NULL;
    int *odd_array = NULL;

    even_array = (int *) malloc(sizeof(int) * array_size);
    odd_array = (int *) malloc(sizeof(int) * array_size);

    for (int i = 0; i < array_size; ++i) {
        even_array[i] = 2 * i;
        odd_array[i] = 2 * i + 1;
    }

    even_array = realloc(even_array, 2 * array_size * sizeof(int));
    for (int j = array_size; j < array_size * 2; ++j) {
        even_array[j] = odd_array[j - array_size];
    }

    sort(even_array, 20);
    for (int k = 0; k < array_size * 2; ++k) {

        printf("%d ", even_array[k]);
    }
    free(odd_array);
    free(even_array);

    return 0;
}

void sort(int *array, int size)
{
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}