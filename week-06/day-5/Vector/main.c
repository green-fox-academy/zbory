#include <stdio.h>
#include "myvector.h"

void print_vector(vector_t *vector);

int double_number(int number);

int cube_number(int number);

int main()
{
    //Creating vector
    printf("Creating vector!\n");
    vector_t *vector;
    create_vector(&vector);
    print_vector(vector);
    printf("The vector is %s!\n", is_empty(vector) ? "empty" : "not empty");

    //Adding items to the back
    printf("Adding items!\n");
    push_back(vector, 3);
    print_vector(vector);
    push_back(vector, 1);
    print_vector(vector);
    push_back(vector, 4);
    push_back(vector, 1);

    print_vector(vector);

    //Insert items
    printf("Inserting items!\n");
    insert_after_index(vector, 7, 2);
    insert_after_index(vector, 8, 2);
    insert_after_index(vector, 9, 2);
    print_vector(vector);
    insert_after_index(vector, 10, 2);

    print_vector(vector);

    //Remove last item
    printf("Pop last item!\n");
    pop_back(vector);

    print_vector(vector);

    //Delete item at index
    printf("Delete at index!\n");
    delete_by_index(vector, 3);
    delete_by_index(vector, 3);
    delete_by_index(vector, 3);
    delete_by_index(vector, 3);

    print_vector(vector);

    //Search for value
    push_back(vector, 6);
    push_back(vector, 5);
    push_back(vector, 13);
    push_back(vector, 12);
    push_back(vector, 11);
    printf("Searching!\n");
    int number = 12;
    print_vector(vector);
    printf("The index of %d is %d\n", number, search(vector, number));

    //Shuffling items
    printf("Shuffling vector!\n");
    print_vector(vector);
    shuffle(vector);
    print_vector(vector);

    //Delete duplicate items
    printf("Delete duplicates!\n");
    push_back(vector, 3);
    push_back(vector, 4);
    push_back(vector, 5);
    push_back(vector, 3);
    print_vector(vector);
    unique(vector);
    print_vector(vector);

    //Transform with callback function
    printf("Transform with parameter function!\n");
    print_vector(vector);
    transform(vector, cube_number);
    print_vector(vector);

    return 0;
}

void print_vector(vector_t *vector)
{
    for (int i = 0; i < get_size(vector); ++i) {
        printf("%d\t", vector->elements[i]);
    }
    printf("(size: %d, capacity: %d)\n", vector->size, vector->capacity);
}

int double_number(int number)
{
    return number * 2;
}

int cube_number(int number)
{
    return number * number * number;
}