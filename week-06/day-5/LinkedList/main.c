#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
    linked_list_t *head;
    create_list(&head);

    printf("The list is %s!\n", is_empty(head) ? "empty" : "not empty");
    printf("Inserting items...\n");
    append_item(head, 42);
    append_item(head, 802701);
    append_item(head, 101);
    prepend_item(head, 7);

    printf("The list is %s!\n", is_empty(head) ? "empty" : "not empty");
    printf("Item count: %d\n", get_ite_count(head));
    printf("Items:\n");
    linked_list_t *it = head;
    while (it->next != NULL){
        printf("%d\n", it->data);
        it = it->next;
    }

    return 0;
}