//
// Created by zbora on 2019-05-17.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

typedef struct linked_list {
    int data;
    struct linked_list *next;
} linked_list_t;

int create_list(linked_list_t **head);

int append_item(linked_list_t *head, int data);

int prepend_item(linked_list_t *head, int data);

int insert_after(linked_list_t *head, int data, linked_list_t *after_this);

int get_ite_count(linked_list_t *head);

#endif //LINKEDLIST_LINKEDLIST_H
