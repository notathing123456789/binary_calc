#ifndef STACK_NUMBER_H
#define STACK_NUMBER_H

#define MAX 100

// NumStack structure definition
typedef struct {
    int top;
    number* items[MAX];
} NumStack;

// NumStack function declarations
void NumStackInitialize(NumStack* stack);
int NumStackIsFull(NumStack* stack);
int NumStackIsEmpty(NumStack* stack);
void NumStackPush(NumStack* stack, number* value);
number* NumStackPop(NumStack* stack);
number* NumStackPeek(NumStack* stack);
void NumStackDisplay(NumStack* stack);

#endif