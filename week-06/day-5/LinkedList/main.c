#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void print_list(linked_list_t *head);

int main()
{
    //Creating list
    linked_list_t *head;
    create_list(&head);

    //Adding items
    printf("The list is %s!\n", is_empty(head) ? "empty" : "not empty");
    printf("Inserting items...\n");
    append_item(head, 42);
    append_item(head, 802701);
    append_item(head, 101);
    prepend_item(head, 7);
    append_item(head, 3);

    //Item count and list
    printf("The list is %s!\n", is_empty(head) ? "empty" : "not empty");
    printf("Item count: %d\n", get_item_count(head));
    printf("Items:\n");
    print_list(head);

    //Deleting item
    int to_delete = 101;
    printf("\nDeleting item %d!\n", to_delete);
    delete_by_value(head, to_delete);
    print_list(head);

    //Insert item after specific value helped by the search function
    int search = 42;
    int insert = 77;
    printf("\nInserting %d after item %d!\n", insert, search);
    insert_after(head, insert, search_value(head, search));
    print_list(head);

    //Insert item before specific value helped by the search function
    int search2 = 77;
    int insert2 = 13;
    printf("\nInserting %d before item %d!\n", insert2, search2);
    insert_before(head, insert2, search_value(head, search));
    print_list(head);

    //Deleting linked list
    printf("\nDeleting list!\n");
    printf("Item count: %d\n", get_item_count(head));
    int i = delete_linked_list(head);
    printf("%d nodes got deleted, including the head", i);


    return 0;
}

void print_list(linked_list_t *head)
{
    linked_list_t *it = head;
    do {
        //head non-item not printed
        it = it->next;
        printf("%d ", it->data);
    } while (it->next != NULL);
}