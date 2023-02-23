#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function prototypes
int some_function_call(void);

void struct_demo(void);
void do_swap();
void swap_two_numbers_wrong(int x, int y);
void swap_two_numbers_correctly(int *x, int*y);
void stack_vs_heap(void);

int main(void)
{
    printf("%s\n", "Hello World!");
}

/* ========== SECTION 1: BASIC CONTROL FLOW ========== */

void if_statement_example(int i)
{
    if (i == 1)
    {
        // do something
    } else if (i == 2)
    {
        // do something else
    } else
    {
        // default thing to do
    }
}

void switch_case_example(int i)
{
    switch (i)
    {
        case 1:
            // do something
            break;
        case 2:
            // do something else
            break;
        default:
            // default thing to do
            break;
    }
}

void goto_example(void)
{
    while (1)
    {
        char smth = 'a';
        if (smth == 'a') goto jump_here;
    }

jump_here:
    return;
}

void loop_example(void)
{
    int integers[] = {1, 2, 3, 4, 5};
    // example of a for loop
    // iterating over an array
    for (int i = 0; i < 5; i++)
    {
        int current = integers[i];
        // do something with current
    }

    // non-example of a for-each loop
    //* for (int i : some_list)
    //* {
    //!     THIS DOES NOT WORK!
    //* }

    int i = 69;
    // terminating while loop
    while (i > 0)
    {
        // do something
        i--;
    }

    // infinite loop
    while (1)
    {
        // do something forever
    }
}

/* ========== SECTION 2: POINTERS AND MEMORY MANAGEMENT ========== */

void do_swap(void)
{
    int x = 69;
    int y = 420;

    printf("x is %i, y is %i\n", x, y);

    swap_two_numbers_correctly(&x, &y);

    printf("after swap, x is %i, y is %i\n", x, y);
}

void swap_two_numbers_wrong(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swap_two_numbers_correctly(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void stack_vs_heap(void)
{
    char stack_str[32];
    //gets(stack_str);
    scanf("%s", stack_str);

    printf("%s\n", stack_str);

    char *heap_str = malloc(32);

    free(heap_str);
}

void aliasing_demo(void)
{
    int *x = malloc(sizeof(int));
    *x = 16;
    int *y = x;
    free(x);
    x = NULL;
}

/* ========== SECTION 3: STRUCTS AND TYPEDEFS ========== */

// declaring a struct
struct thisisastruct
{
    int field1;
    char *field2;
};

// typedef-ing a struct
typedef struct thisisastruct newstruct;

// typedef-ing an existing type
typedef char *string;

void struct_demo(void)
{
    printf("The size of our struct is %lu bytes\n", sizeof(struct thisisastruct));

    string str = "according to all known laws of aviation";

    // declaring a struct on the stack
    struct thisisastruct a_struct;
    a_struct.field1 = 420;
    a_struct.field2 = "nani!?";

    printf("%s\n", a_struct.field2);

    // allocating a new struct on the heap
    newstruct *a_struct2 = malloc(sizeof(newstruct));

    // dereferencing a struct to access its fields
    (*a_struct2).field1 = 69;
    // syntactic sugar for the above operation
    a_struct2->field2 = str;

    // malloc and free should ALWAYS come in pairs
    free(a_struct2);
}