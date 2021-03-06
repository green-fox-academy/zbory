//
// Created by zbora on 2019-05-17.
//
#include <stdlib.h>
#include "linkedlist.h"

int create_list(linked_list_t **head)
{
    *head = (linked_list_t *) malloc(sizeof(linked_list_t));
    if (*head == NULL)
        return 0;
    (*head)->data = 0;
    (*head)->next = NULL;

    return 1;
}

int append_item(linked_list_t *head, int data)
{
    linked_list_t *new_item = (linked_list_t *) malloc(sizeof(linked_list_t));
    if (new_item == NULL)
        return 0;
    new_item->data = data;
    new_item->next = NULL;

    linked_list_t *it = head;
    while (it->next != NULL) {
        it = it->next;
    }
    it->next = new_item;

    return 1;
}

int prepend_item(linked_list_t *head, int data)
{
    linked_list_t *new_item = (linked_list_t *) malloc(sizeof(linked_list_t));
    if (new_item == NULL)
        return 0;
    new_item->data = data;
    new_item->next = head->next;
    head->next = new_item;

    return 1;
}

int insert_after(linked_list_t *head, int data, linked_list_t *after_this)
{
    linked_list_t *new_item = (linked_list_t *) malloc(sizeof(linked_list_t));
    if (new_item == NULL)
        return 0;
    new_item->data = data;
    new_item->next = after_this->next;
    after_this->next = new_item;

    return 1;
}

int insert_before(linked_list_t *head, int data, linked_list_t *before_this)
{
    linked_list_t *new_item = (linked_list_t *) malloc(sizeof(linked_list_t));

    if (new_item == NULL)
        return 0;

    new_item->data = data;

    linked_list_t *it = head;
    while (it->next != NULL) {
        if (it->next == before_this) {
            new_item->next = it->next;
            it->next = new_item;
            break;
        }
        it = it->next;
    }
    return 1;
}

int get_item_count(linked_list_t *head)
{
    int count = 0;
    linked_list_t *it = head;
    while (it->next != NULL) {
        count++;
        it = it->next;
    }
    //count -1 to exclude head
    //count +1 because it doesn't increment at the last item
    return count;
}

int is_empty(linked_list_t *head)
{
    if (head->next == NULL)
        return 1;
    else
        return 0;
}

int delete_by_value(linked_list_t *head, int value)
{
    int deleted_items = 0;
    linked_list_t *previous_item = NULL;
    linked_list_t *it = head;
    while (it->next != NULL) {
        if (it->data == value) {
            previous_item->next = it->next;
            free(it);
            deleted_items++;
            it = previous_item;
        }
        previous_item = it;
        it = it->next;
    }
    return deleted_items;
}

linked_list_t *search_value(linked_list_t *head, int value)
{
    linked_list_t *result = NULL;

    linked_list_t *it = head;
    while (it->next != NULL) {
        if (it->data == value)
            result = it;
        it = it->next;
    }

    return result;
}

int delete_linked_list(linked_list_t *head)
{
    linked_list_t *current = head;
    linked_list_t *temp_next;
    int deleted_node_count = 0;

    do{
        temp_next = current->next;
        if(current != NULL) {
            free(current);
            deleted_node_count++;
        }
        current = temp_next;
    }
    while(temp_next != NULL);

    return deleted_node_count;
}

linked_list_t *insertion_sort(linked_list_t *head)
{
    linked_list_t *result;
    create_list(&result);
    //TODO: implement

}