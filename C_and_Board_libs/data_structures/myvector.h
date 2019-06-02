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

//Creates a vector_t object at the aurgument pointer
int create_vector(vector_t **vector);

//Deletes the vector object, freeing up the allocated memory
void delete_vector(vector_t *vector);

//Adds element to the end of the vector
int push_back(vector_t *vector, int value);

//Inserts element after the argument index
int insert_after_index(vector_t *vector, int value, int index);

//Returns the number of elements in the vector
int get_size(vector_t *vector);

//Returns the capacity of the vector
int get_capacity(vector_t *vector);

//Returns whether the vector is empty or not
int is_empty(vector_t *vector);

//Delete last element of the vector
int pop_back(vector_t *vector);

//Deletes element at the specified index, returns 0 if index is not valid
int delete_by_index(vector_t *vector, int index);

//Returns the index of the value in the vector if found, -1 if not found
int search(vector_t *vector, int value);

//Puts the elements in the vector in a random order
int shuffle(vector_t *vector);

//Removes duplicate elements from the vector
int unique(vector_t *vector);

//If capacity is 4 times larger then element count shrinks the vector to half capacity
int resize_vector(vector_t *vector);

//Applies the argument function to the vector elements
int transform(vector_t *vector, int (*transform)(int));


#endif //VECTOR_MYVECTOR_H
