//
// Created by zbora on 2019-05-20.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int insert_after_index(vector_t *vector, int value, int index)
{
    if (index > vector->size - 1) {
        printf("Index is out of bounds!\n");
        return 0;
    }

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

int get_size(vector_t *vector)
{
    return vector->size;
}

int get_capacity(vector_t *vector)
{
    return vector->capacity;
}

int is_empty(vector_t *vector)
{
    if (vector->size == 0)
        return 1;
    return 0;
}

int pop_back(vector_t *vector)
{
    vector->size--;
    resize_vector(vector);
    return 1;
}

int delete_by_index(vector_t *vector, int index)
{
    if (index > vector->size - 1) {
        printf("Index is out of bounds!\n");
        return 0;
    }

    for (int i = 0; i < vector->size - 1 - index; ++i) {
        vector->elements[index + i] = vector->elements[index + 1 + i];
    }

    vector->size--;
    resize_vector(vector);

    return 1;
}

int search(vector_t *vector, int value)
{
    for (int i = 0; i < vector->size; ++i) {
        if (vector->elements[i] == value)
            return i;
    }
    return -1;
}

int shuffle(vector_t *vector)
{
    srand(time(0));
    vector_t *indexes_temp;
    create_vector(&indexes_temp);
    int *result = (int *) malloc(sizeof(int) * vector->capacity);

    int index;
    int counter = 0;

    while (indexes_temp->size < vector->size) {
        index = rand() % vector->size;
        if (search(indexes_temp, index) < 0) {
            result[counter] = vector->elements[index];
            push_back(indexes_temp, index);
            counter++;
        }
    }
    free(vector->elements);
    free(indexes_temp);
    vector->elements = result;
    return 1;
}

int unique(vector_t *vector)
{
    vector_t *temp_elements;
    create_vector(&temp_elements);
    int *result = (int *) malloc(sizeof(int) * vector->capacity);

    int counter = 0;
    for (int i = 0; i < vector->size; i++) {
        if (search(temp_elements, vector->elements[i]) < 0) {
            result[counter] = vector->elements[i];
            push_back(temp_elements, vector->elements[i]);
            counter++;
        }
    }
    vector->size = counter;
    free(vector->elements);
    free(temp_elements);
    vector->elements = result;
    resize_vector(vector);
}

int resize_vector(vector_t *vector)
{
    if (vector->size < vector->capacity / 4) {
        int *new_capacity = (int *) realloc(vector->elements, sizeof(int) * vector->capacity / 2);
        if (new_capacity == NULL)
            return 0;
        vector->elements = new_capacity;
        vector->capacity /= 2;
    }
    return 1;
}

int transform(vector_t *vector, int (*transform)(int))
{
    for (int i = 0; i < vector->size; ++i) {
        vector->elements[i] = transform(vector->elements[i]);
    }
    return 1;
}