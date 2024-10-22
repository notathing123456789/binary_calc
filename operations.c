#include <stdio.h>
#include "DLL.h"
#include "stack.h"
#include "stack_number.h"
#include "number.h"

/**
 * The functions adds the number if both
 * of their signs are + else
 * the numbers will be subtracted and the
 * sign will be of the number with greater
 * magnitude.
 *
 * addition:
 * first AD's will be added and the carry
 * will be stored in the carry variable
 * addition will start from the tail of AD
 * and we will maintain the position of both
 * the numbers and the greater position will
 * be considered add reduced by 1 until both
 * the positions are equal then both the digits
 * are added
 *
 * then we add add the BD from the tail and
 * also consider the carry variable
 */
void add(NumStack *numstack)
{
    number *num1 = NumStackPop(numstack);
    number *num2 = NumStackPop(numstack);
    number *num3 = create_num();

    if ((num1->sign == 1 && num2->sign == -1) || (num1->sign == -1) && num2->sign == 1)
    {
    }

    int carry = 0;

    if (num1->len_AD != 0 && num2->BD != 0)
    {
        int pos1 = num1->len_AD;
        int pos2 = num2->len_AD;

        if (pos1 != pos2)
        {
            if (pos1 > pos2)
            {
                number *temp = num1;
                num1 = num2;
                num2 = temp;
                int temp2 = pos1;
                pos1 = pos2;
                pos2 = pos1;
            }

            while(pos1 > pos2)
            {
                
            }
        }
    }
}

void Subtract(NumStack *numstack)
{
    number *num1 = NumStackPop(numstack);
    number *num2 = NumStackPop(numstack);
    number *num3 = create_num();

    if ((num1->sign == 1 && num2->sign == -1) || (num1->sign == -1) && num2->sign == 1)
    {
    }

    int carry = 0;

    if (num1->len_AD != 0 && num2->BD != 0)
    {
        int pos1 = num1->len_AD;
        int pos2 = num2->len_AD;

        if (pos1 != pos2)
        {
            if (pos1 > pos2)
            {
                number *temp = num1;
                num1 = num2;
                num2 = temp;
                int temp2 = pos1;
                pos1 = pos2;
                pos2 = pos1;
            }

            while(pos1 > pos2)
            {
                
            }
        }
    }
}

