/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** test
*/

#include <stdio.h>

#include "../../include/formats.h"
#include <stdlib.h>
#include "my.h"

char *my_float_to_str(double nb, char *str, int i, formats_t *formats)
{
    int nb_i = nb;
    int precision = my_compute_power_rec(10, formats->precision);
    int nw_nb2 = (nb * 1000000) - (nb_i * 1000000);
    int nw_nb3 = 0;
    int count = 0;
    int nw_nb = 0;

    if (formats->precision != 0)
        nw_nb2 = (nb * precision) - (nb_i * precision);
    nw_nb3 = nw_nb2;
    for (; nw_nb2 > 0; count++)
        nw_nb2 = nw_nb2 / 10;
    for (; count > 0; i++) {
        nw_nb = (nw_nb3 / my_compute_power_rec(10, count - 1)) - (nw_nb * 10);
        str[i] = nw_nb + 48;
        nw_nb = nw_nb3 / my_compute_power_rec(10, count - 1);
        count--;
    }
    str[i] = '\0';
    return str;
}

char *my_nbr_to_str(double nb, formats_t *formats)
{
    int count = 0;
    char *str;
    int nw_nb = 0;
    int nw_nb2 = nb;
    int i = 0;

    for (; nw_nb2 > 0; count++)
        nw_nb2 = nw_nb2 / 10;
    str = malloc(sizeof(char) * (3 + 2 + count));
    for (i = 0; count > 0; i++) {
        nw_nb = (nb / my_compute_power_rec(10, count - 1)) - (nw_nb * 10);
        str[i] = nw_nb + 48;
        nw_nb = nb / my_compute_power_rec(10, count - 1);
        count--;
    }
    str[i] = '.';
    i++;
    my_float_to_str(nb, str, i, formats);
    return str;
}
