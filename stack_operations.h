#include <stdbool.h>
#define MAX_SIZE 10

// Definition of Stack data type
typedef struct Stack
{
    int stack[MAX_SIZE];  // Array which will be used as stack
    int top;              // Index of top of the stack
}Stack;

// Creates stack in the heap memory
Stack *create_stack()
{
    //1. Allocation of the memory space
    Stack *s = (Stack*)malloc(sizeof(Stack));
    //2. Initialization of top value which allows to track position of last added element in stack. 
    s -> top = -1;
    // Note: Values in the array is not initialized to 0 as it is time costly i.e. O(n). 
    return s;
    // Note: Memory has to be deallocated after the purpose of the list is completed.     
}

// is_empty(address of the stack): Returns boolean value true if the list is empty. 
bool is_empty(Stack **pointerToStack)
{
    // temp variable holds the address of the stack to grant its access and perform operations on it.
    Stack *temp = *pointerToStack; 
    return temp -> top == -1;     
}

// push(address of the stack, element to be added): Adds element in the stack.
void push(Stack **pointerToStack, int data)
{
    Stack *temp = *pointerToStack;
    // To avoid stackoverflow in the memory      
    if (temp -> top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow\n");
        return;
    }
    // index of top element is updated first followed by inserting the data in the stack.
    (temp -> stack)[++(temp -> top)] = data;
}

// pop(address of the stack): Removes top element from the stack.
void pop(Stack **pointerToStack)
{
    Stack *temp = *pointerToStack;
    if (is_empty(&temp)) 
    {
        printf("The list is empty.\n");
    }
    else
    {
        (temp -> stack)[temp ->top] = 0;
        (temp -> top)--;
    }
}

// peek(address of the stack): Returns the top element in the stack.
int peek(Stack **pointerToStack)
{
    Stack *temp = *pointerToStack;
    return (temp -> stack)[temp ->top];
}

// display_stack(address of the stack): Displays the whole stack.
void display_stack(Stack **pointerToStack)
{
    Stack *temp = *pointerToStack;
    
    if (!is_empty(&temp)) 
    {
        printf("Stack: ");
        for(int i = 0; i <= temp -> top; i++)
        {
            if (i == 0) 
            {
                printf("[");
            }
            printf("%d", (temp -> stack)[i]);
            if (i < temp -> top) 
            {
                printf(", ");
            }
            if (i == temp -> top) 
            {
                printf("]");
            }
        }
        printf("\n");
    }
    else
    {
        printf("The list is empty.\n");
    }
}

