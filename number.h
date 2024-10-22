#ifndef NUMBER_H
#define NUMBER_H

struct number {
    int sign;
    DLL* BD;
    int len_BD;
    DLL* AD;
    int len_AD; 
};

typedef struct number number;
number* create_num();
void num_add_BD(number *num, int digit);
void num_add_AD(number *num, int digit);
void display_num(number* num);

#endif