/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** flag_fbigf
*/

#include "my.h"
#include <stdarg.h>

#include "../../include/formats.h"

static void check_spaces(formats_t *formats, int a)
{
    int size = formats->width - len_nb(a) - 1 - formats->precision;

    if (formats->flag1 == 4 && formats->width != 0 && formats->precision != 0) {
        for (int i = 0; i < size; i++)
            my_putchar(' ');
    }
}

int print_roundings(double float_arondis, double b, formats_t *formats, int a)
{
    for (;; float_arondis *= 10) {
        if (float_arondis * 10 > 5) {
            my_put_nbr(b * (my_compute_power_rec(10, formats->precision)) + 1);
            check_spaces(formats, a);
            return 0;
        }
        if (float_arondis * 10 < 5) {
            my_put_nbr(b * my_compute_power_rec(10, formats->precision));
            check_spaces(formats, a);
            return 0;
        }
    }
}

int print_int_roundings(double float_arondis, int a, formats_t *formats)
{
    for (;; float_arondis *= 10) {
        if (float_arondis * 10 > 5) {
            my_put_nbr(a + 1);
            return 0;
        }
        if (float_arondis * 10 < 5 && formats->flag1 != 1) {
            my_put_nbr(a);
            return 0;
        }
        if (float_arondis * 10 < 5 && formats->flag1 == 1) {
            my_put_nbr(a);
            my_putchar('.');
            return 0;
        }
    }
}

static void check_spaces_bef(formats_t *formats, int a)
{
    int size = formats->width - len_nb(a) - 1 - formats->precision;

    if (formats->flag1 == 16 && formats->width != 0 && formats->precision != 0
        && formats->flag5 == 8) {
        my_putchar(' ');
        for (int i = 0; i < size - 1; i++)
            my_putchar('0');
    }
}

void print_a(int a, formats_t *formats)
{
    int size = formats->width - len_nb(a) - 1 - formats->precision;

    if (a < 0 || formats->flag1 == 2 && a > 0)
        size--;
    if (formats->flag1 == 16 && formats->width != 0 && formats->flag5 == 0
        || formats->flag1 == 0 && formats->width > size && formats->flag5 == 0)
        for (int i = 0; i < size; i++)
            my_putchar(' ');
    check_spaces_bef(formats, a);
    if (formats->flag1 == 2 && a > 0)
        my_putchar('+');
    if (formats->flag1 == 16 && formats->width == 0 && a > 0)
        my_putchar(' ');
    if (a < 0)
        my_putchar('-');
    if (formats->flag5 == 8 && formats->flag1 != 16)
        for (int i = 0; i < size; i++)
            my_putchar('0');
    my_put_nbr(a);
    my_putchar('.');
}

int check_precision(formats_t *formats)
{
    if (formats->precision == 0 && formats->point == 0)
        formats->precision = 6;
    return formats->precision;
}

int specifier_fbigf(va_list arguments_list, formats_t *formats)
{
    double nb = va_arg(arguments_list, double);
    int a = nb;
    int counter = len_nb(a) + (check_precision(formats) + 1);
    double b = (nb - a);
    long long unsigned int_arrondis = b * my_compute_power_rec(10,
        check_precision(formats));
    long double float_arondis = (b * my_compute_power_rec(10,
            check_precision(formats)) - int_arrondis);

    if (formats->point == 1 && formats->precision == 0) {
        print_int_roundings(float_arondis, a, formats);
        return counter;
    }
    print_a(a, formats);
    print_roundings(float_arondis, b, formats, a);
    if (formats->precision > len_nb(b * my_compute_power_rec(10,
                formats->precision)))
        for (int i = 0; i < formats->precision - 1; i++)
            my_putchar('0');
    return counter;
}
