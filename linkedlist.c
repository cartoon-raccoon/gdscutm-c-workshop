#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

void populate_list(linkedlist *list);

// driver code
int main(void)
{
    linkedlist list;
    list.head = NULL;
    
    // test printing on an empty list
    linkedlist_print(&list);

    // populate the list with numbers
    populate_list(&list);

    // print the new list
    linkedlist_print(&list);

    // try removing an item from the list
    int item1 = linkedlist_remove(&list, 4);
    printf("Removed item at index 4, got %i\n", item1);

    // try removing from an out of bounds index
    int item2 = linkedlist_remove(&list, 10);
    printf("Out of bounds was handled, got %i\n", item2);

    // try and out of bounds index
    int *idx = linkedlist_index(&list, 10);
    if (idx == NULL) {
        printf("Out of bounds access was handled correctly!\n");
    }

    linkedlist_print(&list);

    return 0;
}

void populate_list(linkedlist *list)
{
    for (int i = 0; i < 5; i++) {
        linkedlist_push(list, i + 1);
    }

    linkedlist_append(list, 6);
    linkedlist_append(list, 7);
}

linkedlist *linkedlist_create()
{
    // allocate memory for a new linked list
    linkedlist *list = malloc(sizeof(linkedlist));
    if (!list)
    {
        return NULL;
    }
    // set list head to NULL
    list->head = NULL;

    return list;
}

void linkedlist_destroy(linkedlist *list)
{
    // allocate a cursor variable
    node *cur = list->head;

    /* Iterate over the entire list and deallocate
    all nodes, stopping when we hit a null ptr */
    while (cur)
    {
        // declare a stack variable to free
        node *to_free = cur;
        // advance the cursor to the next node
        cur = cur->next;
        // we are now free to deallocate
        free(to_free);
    }

    // deallocate the list itself
    free(list);
}

int linkedlist_push(linkedlist *list, int item)
{
    // allocate memory for a new node
    node *n = malloc(sizeof(node));
    // check if allocation failed
    if (n == NULL)
    {
        return 0;
    }
    // store the list head in a temporary stack variable
    node* temp = list->head;

    // initialize the new node
    n->value = item;
    n->next = temp;

    // store n as the list head
    list->head = n;

    return 1;
}

int linkedlist_append(linkedlist *list, int item)
{
    // create a node by allocating memory
    node *n = malloc(sizeof(node));
    // check if allocation failed
    if (n == NULL)
    {
        return 0;
    }

    // initialize the new node
    n->value = item;
    n->next = NULL;

    if (list->head == NULL)
    {
        // if list is empty, directly assign to head
        list->head = n;
    }
    else
    {
        // else iterate to the end of the list
        node *ptr = list->head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
    }

    return 1;
}

int linkedlist_remove(linkedlist *list, int idx)
{
    // declare and initialize a cursor variable
    node *cur = list->head;
    // iterate to the item before the item to remove
    for (int i = 0; i < idx - 1; ++i)
    {
        // check for out of bounds errors
        if (cur == NULL) return 0;
        cur = cur->next;
    }

    // get the node we want to remove
    node *rem = cur->next;
    // get the rest of the list
    node *rest = rem->next;
    // extract the value to return
    int ret = rem->value;

    // have the current node point to the rest of the list
    cur->next = rest;

    // since the node we want to remove is no longer pointed to,
    // we can safely free it
    free(rem);

    return ret;
}

int *linkedlist_index(linkedlist *list, int idx)
{
    // declare and initialize a cursor variable
    node *cur = list->head;
    // iterate to the index
    for (int i = 0; i < idx; ++i)
    {
        cur = cur->next;
        // if we've reached the end, then we have
        // an out of bounds error
        if (cur == NULL)
            return NULL;
    }

    return &(cur->value);
}

void linkedlist_print(linkedlist *list)
{
    node *cur = list->head;
    while (cur)
    {
        printf("%i -> ", cur->value);
        cur = cur->next;
    }

    printf("END\n");

    return;
}
