#include "stack_number.h"
#include <stdio.h>
#include <stdlib.h>
#include "number.h"

// Function to initialize the stack
void NumStackInitialize(NumStack* stack) {
    stack->top = -1;
}

// Function to check if the stack is full
int NumStackIsFull(NumStack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int NumStackIsEmpty(NumStack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void NumStackPush(NumStack* stack, number* value) {
    if (NumStackIsFull(stack)) {
        printf("NumStack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an item from the stack
number* NumStackPop(NumStack* stack) {
    if (NumStackIsEmpty(stack)) {
        printf("NumStack underflow\n");
        return NULL; // Return null character when stack is empty
    }
    return stack->items[stack->top--];
}

// Function to peek the top item of the stack
number* NumStackPeek(NumStack* stack) {
    if (NumStackIsEmpty(stack)) {
        printf("NumStack is empty\n");
        return '\0';
    }
    return stack->items[stack->top];
}

void NumStackDisplay(NumStack* stack)
{
    NumStack s2;
    NumStackInitialize(&s2);
    printf("Stack contents are ");

    while(!NumStackIsEmpty(stack))
    {
        number* c = NumStackPop(stack);
        display_num(c);
        NumStackPush(&s2, c);
    }

    while(!NumStackIsEmpty(&s2))
        NumStackPush(stack, NumStackPop(&s2));
    
}