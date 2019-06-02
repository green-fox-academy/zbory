//
// Created by zbora on 2019-05-16.
//

#ifndef PERCENTILE_MATRIX_H
#define PERCENTILE_MATRIX_H

typedef struct matrix{
  int *elements;
  int rows;
  int columns;
} matrix_t;


//Creates a matrix object
matrix_t *create_matrix(int rows, int columns);

//Returns an element of the matrix by row/column index
int get_matrix_element(matrix_t *matrix, int row_index, int column_index);

//Set an element of the matrix by row/column index
void set_matrix_element(matrix_t *matrix, int row_index, int column_index, int element);

//Deletes the matrix object, frees up the allocated memory
void delete_matrix(matrix_t *matrix);

//Sorts the elements stored in the matrix and returns them as an array at the argument pointer
void get_sorted_items(matrix_t *matrix, int **result);

//Returns the size/element count of the matrix
int get_item_count(matrix_t *matrix);

#endif //PERCENTILE_MATRIX_H
