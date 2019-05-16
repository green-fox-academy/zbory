#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int get_percentile(matrix_t *matrix, int percentile);

int main()
{
    int rows;
    int columns;
    printf("Please input the dimensions of the matrix!\n");
    scanf("%d %d", &columns, &rows);

    matrix_t *matrix = create_matrix(rows, columns);

    printf("Please input the matrix values!\n");
    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < columns; ++i) {
            int temp;
            scanf("%d", &temp);
            set_matrix_element(matrix, i, j, temp);
        }
    }
    printf("Your matrix is:\n");
    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < columns; ++i) {
            printf("%d ", get_matrix_element(matrix, i, j));
        }
        printf("\n");
    }

    int percentile = 0;
    printf("\nInput the percentile you'd like to know!\n");
    scanf("%d", &percentile);
    printf("The %dth percentile item is: %d", percentile, get_percentile(matrix, percentile));

    return 0;
}

int get_percentile(matrix_t *matrix, int percentile)
{
    int *sorted = NULL;
    get_sorted_items(matrix, &sorted);

    float index = percentile / 100.0f * get_item_count(matrix);

    return sorted[(int) index];
}