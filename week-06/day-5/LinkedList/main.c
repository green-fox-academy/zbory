#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void print_list(linked_list_t *head);

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
    append_item(head, 3);

    printf("The list is %s!\n", is_empty(head) ? "empty" : "not empty");
    printf("Item count: %d\n", get_ite_count(head));
    printf("Items:\n");
    print_list(head);

    int to_delete = 101;
    printf("Deleting item %d!\n", to_delete);
    delete_by_value(head, to_delete);
    print_list(head);


    return 0;
}

void print_list(linked_list_t *head)
{
    linked_list_t *it = head;
    do {
        //head non-item not printed
        it = it->next;
        printf("%d\n", it->data);
    } while (it->next != NULL);
}