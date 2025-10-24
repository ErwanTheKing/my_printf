/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** The my_put_float.c
*/

#include "my.h"

void my_putfloat(float nb)
{
    int a = nb;
    int b = (nb * 1000000) - (a * 1000000);

    my_put_nbr(a);
    my_putchar('.');
    if (b < 10) {
        my_putchar('0');
        my_put_nbr(b);
    } else
        my_put_nbr(b);
}
