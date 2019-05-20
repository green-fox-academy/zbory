//
// Created by zbora on 2019-05-20.
//

#ifndef VECTOR_MYVECTOR_H
#define VECTOR_MYVECTOR_H

typedef struct vector {
    int *elements;
    int size;
    int capacity;
} vector_t;

int create_vector(vector_t **vector);

int push_back(vector_t *vector, int value);

int insert_after_index(vector_t *vector, int value, int index);

int get_size(vector_t *vector);

int get_capacity(vector_t *vector);

int is_empty(vector_t *vector);

int pop_back(vector_t *vector);

int delete_by_index(vector_t *vector, int index);

int search(vector_t *vector, int value);

int shuffle(vector_t *vector);

int unique(vector_t *vector);

int resize_vector(vector_t *vector);

int transform(vector_t *vector, int (*transform)(int));


#endif //VECTOR_MYVECTOR_H
