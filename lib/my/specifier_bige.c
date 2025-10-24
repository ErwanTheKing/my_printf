/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** flag_E
*/

#include <stdarg.h>
#include "my.h"
#include "formats.h"

static int my_put_e(double nb)
{
    int count = 0;
    double nb_temp = nb;
    int nb_decimals = 6;

    for (; nb_temp > 9; count++)
        nb_temp = nb_temp / 10;
    my_putfloat(nb_temp);
    if (count < 10)
        my_printf("E+0%d", count);
    else
        my_printf("E+%d", count);
    count = count + nb_decimals;
    return count;
}

int specifier_bige(va_list arguments_list, formats_t *formats)
{
    double nb = va_arg(arguments_list, double);
    int count = 0;

    count = my_put_e(nb);
    return count;
}
