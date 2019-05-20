#include <stdio.h>
#include "myvector.h"

void print_vector(vector_t *vector);

int main()
{
    //Creating vector
    printf("Creating vector!\n");
    vector_t* vector;
    create_vector(&vector);
    print_vector(vector);

    //Adding items to the back
    printf("Adding items!\n");
    push_back(vector,3);
    print_vector(vector);
    push_back(vector,1);
    print_vector(vector);
    push_back(vector,4);
    push_back(vector,1);

    print_vector(vector);

    //Insert items
    printf("Inserting items!\n");
    insert_after(vector, 7, 2);
    insert_after(vector, 8, 2);
    insert_after(vector, 9, 2);
    print_vector(vector);
    insert_after(vector, 10, 2);

    print_vector(vector);

    return 0;
}

void print_vector(vector_t *vector){
    for (int i = 0; i < vector->size; ++i) {
        printf("%d ", vector->elements[i]);
    }
    printf("(size: %d, capacity: %d)\n", vector->size ,vector->capacity);
}
