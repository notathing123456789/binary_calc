#include "stack.h"

// Function to initialize the stack
void StackInitialize(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is full
int StackIsFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int StackIsEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void StackPush(Stack* stack, char value) {
    if (StackIsFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an item from the stack
char StackPop(Stack* stack) {
    if (StackIsEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0'; // Return null character when stack is empty
    }
    return stack->items[stack->top--];
}

// Function to peek the top item of the stack
char StackPeek(Stack* stack) {
    if (StackIsEmpty(stack)) {
        printf("Stack is empty\n");
        return '\0';
    }
    return stack->items[stack->top];
}

void StackDisplay(Stack* stack)
{
    Stack s2;
    StackInitialize(&s2);
    printf("Stack contents are ");

    while(!StackIsEmpty(stack))
    {
        char c = StackPop(stack);
        printf("%c,", c);
        StackPush(&s2, c);
    }

    while(!StackIsEmpty(&s2))
        StackPush(stack, StackPop(&s2));
    
}