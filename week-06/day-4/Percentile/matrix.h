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

matrix_t *create_matrix(int rows, int columns);

int get_matrix_element(matrix_t *matrix, int row_index, int column_index);

void set_matrix_element(matrix_t *matrix, int row_index, int column_index, int element);

void delete_matrix(matrix_t *matrix);

void get_sorted_items(matrix_t *matrix, int **result);

int get_item_count(matrix_t *matrix);

#endif //PERCENTILE_MATRIX_H
