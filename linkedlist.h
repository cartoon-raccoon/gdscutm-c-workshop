// declaring a node struct
typedef struct node {
    int value;
    struct node *next;
} node;

// declaring the wrapper struct
typedef struct linkedlist {
    struct node *head;
} linkedlist;

// ====== FUNCTION PROTOTYPES ====== //

// constructor and destructor functions

/// Allocates a new linked list.
linkedlist *linkedlist_create(void);

/// Deallocates all the nodes in `list` and then deallocates `list` itself.
void linkedlist_destroy(linkedlist *list);

// linked list methods

/// Pushes a new item to the head of the linked list,
/// moving all items down by one index.
int linkedlist_push(linkedlist *list, int item);

/// Appends a new item to the end of the linked list.
/// Item indexes do not change.
int linkedlist_append(linkedlist *list, int item);

/// Removes an item from the list at the specified index,
/// deallocating the node and returning its value.
int linkedlist_remove(linkedlist *list, int idx);

/// Returns the value of the node at the specified index.
int *linkedlist_index(linkedlist *list, int idx);

/// Prints all the list's items.
void linkedlist_print(linkedlist *list);