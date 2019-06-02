//
// Created by zbora on 2019-05-17.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

typedef struct linked_list {
    int data;
    struct linked_list *next;
} linked_list_t;

//Creates a linked list object
int create_list(linked_list_t **head);

//Appends a new list element at the end of the list
int append_item(linked_list_t *head, int data);

//Add an element at the beginning of the list (after the head)
int prepend_item(linked_list_t *head, int data);

//Inserts an element after the pointed list element
int insert_after(linked_list_t *head, int data, linked_list_t *after_this);

//Inserts an element before the pointed list element
int insert_before(linked_list_t *head, int data, linked_list_t *before_this);

//Returns the number of elements in the list, empty head not counted
int get_item_count(linked_list_t *head);

//Returns whether the list is empty or not
int is_empty(linked_list_t *head);

//Deletes all nodes containing the argument value
int delete_by_value(linked_list_t *head, int value);

//If the argument value is contained in the list, returns a pointer to it, otherwise reuturns NULL
linked_list_t *search_value(linked_list_t *head, int value);

//Deletes the linked list object, frees up the memory, returns the (number of deleted nodes + empty head)
int delete_linked_list(linked_list_t *head);

linked_list_t *insertion_sort(linked_list_t *head);



#endif //LINKEDLIST_LINKEDLIST_H
