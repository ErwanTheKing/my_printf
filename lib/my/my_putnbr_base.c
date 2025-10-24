/*
** EPITECH PROJECT, 2025
** my_putnbr_base
** File description:
** test
*/

#include <stdio.h>
#include "my.h"

int my_putnbr_base(unsigned int nbr, char const *base)
{
    int nbr_base = my_strlen(base);
    int res_base = 0;

    if (nbr < 0) {
        nbr = nbr * -1;
    }
    if (nbr > 0) {
        res_base = nbr / nbr_base;
        nbr = nbr % nbr_base;
        my_putnbr_base(res_base, base);
        if (nbr >= 10 && nbr <= 15) {
            my_putchar(base[nbr] + 32);
        } else {
            my_putchar(nbr + 48);
        }
    }
    return (0);
}
