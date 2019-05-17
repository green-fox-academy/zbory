//
// Created by zbora on 2019-05-17.
//
#include <stdlib.h>
#include "linkedlist.h"

int create_list(linked_list_t **head)
{
    *head = (linked_list_t *) malloc(sizeof(linked_list_t));
    (*head)->data = 0;
    (*head)->next = NULL;
}

int append(linked_list_t *head, int data)
{
    linked_list_t *new_item = (linked_list_t *) malloc(sizeof(linked_list_t));
    if (new_item == NULL)
        return 0;
    new_item->data = data;
    new_item->next = NULL;

    head->next = new_item;
    return 1;
}

int prepend_item(linked_list_t *head, int data){
    linked_list_t *new_item = (linked_list_t *) malloc(sizeof(linked_list_t));
    if (new_item == NULL)
        return 0;
    new_item->data = data;
    new_item->next = head->next;
    head->next = new_item;
}