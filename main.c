#include <stdio.h>
#include "DLL.h"
#include "stack.h"
#include "stack_number.h"
#include "number.h"

enum cases
{
    ERROR,
    OPERATOR,
    NUMBER,
    DOT,
    START
};

/**
 * checks if the character
 * is a number
 */
int isNumber(char c)
{
    int a = c - '0';
    return (a >= 0 && a <= 9);
}

/**
 * checks if a character is
 * a acceptable mathematical
 * operator
 */
int isOp(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return 1;
    default:
        return 0;
    }
}

NumStack numstack;
Stack charstack;

/**
 * process the characters given
 * return 0 for an error
 * return 1 if an operand was found
 * return 2 otherwise
 * properly enters the number in number
 * stack by analyzing if current character
 * and the previous state
 *
 * if prev state:
 * START
 * 1]only numbers allowed, create a new
 * number and push into stack, change
 * state to NUMBER
 * NUMBER
 * 1]current number: pop out the prev
 * number and add the new digit to it
 * 2]if DOT change the state to dot
 * 3]if operator add the operator to
 * charStack and change state to OP
 * DOT
 * 1]number add modify number so that
 * a decimal gets added to it
 * appropriately
 * 2]if operator add oeprator to
 * stack and change state
 * OP
 * 1]only number change state to
 * NUM
 */
int process(char ch)
{
    static int state = START;

    switch (state)
    {
    case START:
        if (isNumber(ch))
        {
            number *num = create_num();
            num_add_BD(num, ch - '0');
            NumStackPush(&numstack, num);
            state = NUMBER;
            return NUMBER;
        }
        else
            return ERROR;
        break;
    case NUMBER:
        if (isNumber(ch))
        {
            number *num = NumStackPeek(&numstack);
            num_add_BD(num, ch - '0');
            return NUMBER;
        }
        else if (ch == '.')
        {
            state = DOT;
            return NUMBER;
        }
        else
        {
            if (isOp(ch))
            {
                StackPush(&charstack, ch);
                state = OPERATOR;
                return OPERATOR;
            }
            else
                return ERROR;
        }
    case DOT:
        if (isNumber(ch))
        {
            number *num = NumStackPeek(&numstack);
            num_add_AD(num, ch - '0');
            return NUMBER;
        }
        else
        {
            if (isOp(ch))
            {
                StackPush(&charstack, ch);
                state = OPERATOR;
                return OPERATOR;
            }
            else
                return ERROR;
        }
        break;
    case OPERATOR:
        if (isNumber(ch))
        {
            number *num = create_num();
            num_add_BD(num, ch - '0');
            NumStackPush(&numstack, num);
            state = NUMBER;
            return NUMBER;
        }
        else
            return ERROR;
        break;
    default:
        return ERROR;
        break;
    }
}

int OPPrec(char ch)
{
    switch (ch)
    {
    case '/':
        return 4;
        break;
    case '*':
        return 3;
        break;
    case '+':
        return 2;
        break;
    case '-':
        return 1;
        break;
    default:
        break;
    }
}

int main()
{
    char c;
    NumStackInitialize(&numstack);
    StackInitialize(&charstack);

    while ((c = getchar()) != '\n')
    {
        int num = process(c);
        if (num == OPERATOR)
        {
            char op1 = StackPop(&charstack);
            while(!StackIsEmpty(&charstack))
            {
                char op2 = StackPeek(&charstack);
                if(OPPrec(op1) > OPPrec(op2))
                    break;
                printf("performed %c operation", op2);
                StackPop(&charstack);
            }
            
            StackPush(&charstack, op1);
        }
    }
    NumStackDisplay(&numstack);
    StackDisplay(&charstack);

    while(!StackIsEmpty(&charstack))
    {
        char op1 = StackPop(&charstack);
        printf("performed %c operation ", op1);
    }

    return 0;
}
