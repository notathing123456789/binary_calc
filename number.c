#include "number.h"
#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

/**
 * the fucntion will
 * create a new
 * number data type
 * variable
 */
number *create_num()
{
    number *n = (number *)malloc(sizeof(number));
    n->AD = (DLL *)malloc(sizeof(DLL));
    n->BD = (DLL *)malloc(sizeof(DLL));
    DLL_init(n->AD);
    DLL_init(n->BD);

    n->len_AD = 0;
    n->len_BD = 0;
    n->sign = 1;
    return n;
}

void num_add_BD(number *num, int digit)
{
    insertAtTail(num->BD, digit);
    num->len_BD++;
}

void num_add_AD(number *num, int digit)
{
    insertAtTail(num->AD, digit);
    num->len_AD++;
}
/**
 * display the number
 * by first iterating through the BD
 * then through the AD
 */
void display_num(number *num)
{
    DLL_node *temp = num->BD->head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    temp = num->AD->head;
    if (temp == NULL)
    {
        printf(",");
        return;
    }
    printf(".");

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf(",");
}