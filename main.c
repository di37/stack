#include <stdio.h>
#include <stdlib.h>
#include "stack_operations.h"

int main()
{
    Stack *new_stack = create_stack();
    
    push(&new_stack, 10);
    push(&new_stack, 120);
    display_stack(&new_stack);
    push(&new_stack, 5);
    display_stack(&new_stack);
    pop(&new_stack);
    push(&new_stack, 15);
    push(&new_stack, 30);
    push(&new_stack, 4);
    display_stack(&new_stack);
    printf("Top element in stack: %d\n", peek(&new_stack));
    free(new_stack);           // Deallocating the memory space used in heap
    new_stack = NULL;          // new_stack variable is initialized to NULL
    return 0;
}