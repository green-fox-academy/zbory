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

int insert_after(vector_t *vector, int value, int index);



#endif //VECTOR_MYVECTOR_H
