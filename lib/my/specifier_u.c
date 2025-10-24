/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** test
*/

#include "../../include/my.h"
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#include "../../include/formats.h"

int my_put_nbru(unsigned long long nb)
{
    int modulo = 10;
    int res_modulo = 0;

    if (nb < 10) {
        my_putchar(nb + 48);
    } else if (nb >= 10){
        res_modulo = nb % modulo;
        nb = nb / 10;
        my_put_nbru(nb);
        my_putchar(res_modulo + 48);
    }
    return (0);
}

static void put_length(unsigned long long nb, formats_t *formats)
{
    if (formats->length == 0)
        my_put_nbru((unsigned int)nb);
    if (formats->length == 1)
        my_put_nbru((unsigned short)nb);
    if (formats->length == 128)
        my_put_nbru((unsigned char)nb);
    if (formats->length == 256 || formats->length == 4 || formats->length == 2
        || formats->length == 16 || formats->length == 32)
        my_put_nbru(nb);
}

static int put_flag(unsigned long long nb, formats_t *formats, int count)
{
    int a = 0;

    if (formats->flag1 == 8 || formats->flag2 == 8 || formats->flag3 == 8) {
        for (a += len_nb(nb); a < formats->width; a++) {
            my_putchar('0');
            count++;
        }
    }
    return count;
}

static int put_flag2(unsigned long long nb, formats_t *formats, int count)
{
    if (formats->flag1 == 4 || formats->flag2 == 4 || formats->flag3 == 4) {
        for (int a = formats->precision; a < formats->width; a++) {
            my_putchar(' ');
            count++;
        }
    }
    return count;
}

static int put_width(unsigned long long nb, formats_t *formats, int count)
{
    int a = 1;

    if (formats->precision == 0)
        a = a + 2;
    if (formats->precision != 0 && nb > 0)
        a = a - 2;
    if (formats->precision != 0 && formats->width != 0)
        a = a + 2;
    for (a += len_nb(nb) - 2; a + formats->precision <= formats->width; a++) {
        my_putchar(' ');
        count++;
    }
    return count;
}

static int put_precision(unsigned long long nb, formats_t *formats, int count)
{
    for (int a = len_nb(nb); a < formats->precision; a++) {
        my_putchar('0');
        count++;
    }
    return count;
}

int put_u(unsigned long long nb, formats_t *formats, int count)
{
    if (formats->flag1 != 0)
        count += put_flag(nb, formats, count);
    if (formats->precision != 0)
        count += put_precision(nb, formats, count);
    if (formats->precision == 0 && formats->point == 1 && nb == 0)
        return count;
    if (formats->precision == 0 && nb == 0) {
        put_length(nb, formats);
        return count;
    }
    put_length(nb, formats);
    if (formats->flag1 == 4 || formats->flag2 == 4 || formats->flag3 == 4)
        count += put_flag2(nb, formats, count);
    count += len_nb(nb);
    return count;
}

int specifier_u(va_list arguments_list, formats_t *formats)
{
    int count = 0;
    unsigned long long nb = 0;

    if (formats->length == 0 || formats->length == 1 || formats->length == 128)
        nb = va_arg(arguments_list, unsigned int);
    if (formats->length == 2)
        nb = va_arg(arguments_list, unsigned long);
    if (formats->length == 256)
        nb = va_arg(arguments_list, unsigned long long);
    if (formats->length == 16)
        nb = va_arg(arguments_list, uintmax_t);
    if (formats->length == 32)
        nb = va_arg(arguments_list, size_t);
    if (formats->width != 0 && (formats->flag1 != 4 && formats->flag2 != 4
            && formats->flag3 != 4) && (formats->flag1 != 8
            && formats->flag2 != 8 && formats->flag3 != 8))
        count += put_width(nb, formats, count);
    count += put_u(nb, formats, count);
    return count;
}
