#ifndef STACK_H
#define STACK_H

#define MAX 100
#include <stdio.h>
#include <stdlib.h>

// Stack structure definition
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Stack function declarations
void StackInitialize(Stack* stack);
int StackIsFull(Stack* stack);
int StackIsEmpty(Stack* stack);
void StackPush(Stack* stack, char value);
char StackPop(Stack* stack);
char StackPeek(Stack* stack);
void StackDisplay(Stack* stack);
#endif // STACK_H
