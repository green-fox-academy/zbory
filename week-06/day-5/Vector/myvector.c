//
// Created by zbora on 2019-05-20.
//


#include <stdlib.h>
#include "myvector.h"

int create_vector(vector_t **vector)
{
    vector_t *new_vector = (vector_t *) malloc(sizeof(vector_t));

    new_vector->size = 0;
    new_vector->capacity = 1;
    new_vector->elements = (int *) malloc(sizeof(int) * new_vector->capacity);

    if (new_vector->elements == NULL)
        return 0;

    *vector = new_vector;
    return 1;
}

int push_back(vector_t *vector, int value)
{
    if (vector->size + 1 == vector->capacity) {
        int *new_capacity = (int *) realloc(vector->elements, sizeof(int) * vector->capacity * 2);
        if (new_capacity == NULL)
            return 0;
        vector->elements = new_capacity;
        vector->capacity *= 2;
    }

    vector->elements[vector->size] = value;
    vector->size++;

    return 1;
}

int insert_after(vector_t *vector, int value, int index)
{
    if (vector->size + 1 == vector->capacity) {
        int *new_capacity = (int *) realloc(vector->elements, sizeof(int) * vector->capacity * 2);
        if (new_capacity == NULL)
            return 0;
        vector->elements = new_capacity;
        vector->capacity *= 2;
    }
    for (int i = 0; i < vector->size - 1 - index; ++i) {
        vector->elements[vector->size - i] = vector->elements[vector->size - 1 - i];
    }
    vector->elements[index + 1] = value;
    vector->size++;

    return 1;
}

