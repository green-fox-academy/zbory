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

    printf("Hello, World!\n");
    return 0;
}