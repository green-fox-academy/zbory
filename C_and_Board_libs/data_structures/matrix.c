//
// Created by zbora on 2019-05-16.
//

#include <stdlib.h>
#include "matrix.h"

matrix_t *create_matrix(int rows, int columns)
{
    matrix_t *matrix = (matrix_t *) malloc(sizeof(matrix_t));
    matrix->columns = columns;
    matrix->rows = rows;
    matrix->elements = (int *) malloc(sizeof(int) * rows * columns);
    return matrix;
}

int get_matrix_element(matrix_t *matrix, int row_index, int column_index)
{
    return matrix->elements[row_index * matrix->rows + column_index];
}

void set_matrix_element(matrix_t *matrix, int row_index, int column_index, int element)
{
    matrix->elements[row_index * matrix->rows + column_index] = element;
}

void delete_matrix(matrix_t *matrix)
{
    free(matrix->elements);
    free(matrix);
}

void get_sorted_items(matrix_t *matrix, int **result)
{
    int item_count = matrix->rows * matrix->columns;
    *result = (int*) malloc(item_count);

    for (int i = 0; i < item_count; ++i) {
        (*result)[i] = matrix->elements[i];
    }
    for (int i = 0; i < item_count; ++i) {
        for (int j = i; j < item_count; ++j) {
            if ((*result)[i] > (*result)[j]) {
                int temp = (*result)[i];
                (*result)[i] = (*result)[j];
                (*result)[j] = temp;
            }
        }
    }
}

int get_item_count(matrix_t *matrix)
{
    return matrix->rows * matrix->columns;
}