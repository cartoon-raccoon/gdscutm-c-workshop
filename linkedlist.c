#include <stdio.h>
#include <stdlib.h>

#include "liblinkedlist.h"

void populate_list(linkedlist *list);

// driver code
int main(void)
{  
    linkedlist *list = linkedlist_create();
    
    // test printing on an empty list
    linkedlist_print(list);

    // populate the list with numbers
    populate_list(list);

    // print the new list
    linkedlist_print(list);

    // try removing an item from the list
    int item1 = linkedlist_remove(list, 4);
    printf("Removed item at index 4, got %i\n", item1);

    // try popping from the list
    int item2 = linkedlist_pop(list);
    printf("Popped from list, got %i\n", item2);

    // try removing from an out of bounds index
    int item3 = linkedlist_remove(list, 10);
    printf("Out of bounds was handled, got %i\n", item3);

    // try an out of bounds index
    int *idx = linkedlist_index(list, 10);
    if (idx == NULL)
        printf("Out of bounds access was handled correctly!\n");

    linkedlist_print(list);

    linkedlist_destroy(list);
    list = NULL;

    return 0;
}

void populate_list(linkedlist *list)
{
    for (int i = 0; i < 5; i++)
        linkedlist_push(list, i + 1);

    linkedlist_append(list, 6);
    linkedlist_append(list, 7);
}