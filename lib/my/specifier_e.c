/*
** EPITECH PROJECT, 2025
** flag_e
** File description:
** flag_e
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

#include "../../include/formats.h"

static int print_roundings(double float_arondis, double b, formats_t *formats)
{
    for (; 1 == 1; float_arondis *= 10) {
        if (float_arondis * 10 > 5) {
            my_put_nbr(b * (my_compute_power_rec(10, formats->precision)) + 1);
            return 0;
        }
        if (float_arondis * 10 < 5) {
            my_put_nbr(b * my_compute_power_rec(10, formats->precision));
            return 0;
        }
    }
}

static void display(int count)
{
    if (count < 10)
        my_printf("e+0%d", count);
    else
        my_printf("e+%d", count);
}

static int my_put_e(long double nb, formats_t *formats)
{
    int a = nb;
    int count = len_nb(a) - 1;
    double b = 0;
    int int_arrondis = 0;
    double float_arondis = 0;

    for (int temp = 0; a > 9; temp++)
        a = a / 10;
    b = (nb / my_compute_power_rec(10, count)) - a;
    my_put_nbr(a);
    my_putchar('.');
    if (formats->precision == 0)
        formats->precision = 6;
    int_arrondis = b * my_compute_power_rec(10, formats->precision);
    float_arondis = b * my_compute_power_rec(10, formats->precision);
    float_arondis -= int_arrondis;
    print_roundings(float_arondis, b, formats);
    display(count);
    count = count + formats->precision + 5;
    return count;
}

int specifier_e(va_list arguments_list, formats_t *formats)
{
    int nb = 0;
    int count = 0;

    if (formats->length != 8)
        nb = va_arg(arguments_list, double);
    if (formats->length == 8)
        nb = va_arg(arguments_list, double long);
    count = my_put_e(nb, formats);
    return count;
}
