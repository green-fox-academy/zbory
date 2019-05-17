#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
    linked_list_t *head;
    create_list(&head);
    append_item(head, 42);
    append_item(head, 802701);
    append_item(head, 101);
    prepend_item(head, 7);

    linked_list_t *it = head;
    while (it->next != NULL){
        printf("%d\n", it->data);
        it = it->next;
    }

    return 0;
}