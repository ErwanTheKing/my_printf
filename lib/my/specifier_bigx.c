/*
** EPITECH PROJECT, 2025
** flag_bixx
** File description:
** flag_bigx
*/

#include "../../include/my.h"
#include <stdarg.h>
#include "../../include/formats.h"

static int my_putnbr_base5(unsigned long long nbr, char const *base)
{
    int nbr_base = my_strlen(base);
    unsigned long long res_base = 0;

    if (nbr > 0) {
        res_base = nbr / nbr_base;
        nbr = nbr % nbr_base;
        my_putnbr_base5(res_base, base);
        if (nbr >= 10 && nbr <= 15) {
            my_putchar(base[nbr]);
        } else {
            my_putchar(nbr + 48);
        }
    }
    return 0;
}

static int count_putnbr_base5(unsigned int nbr, char const *base)
{
    int nbr_base = my_strlen(base);
    int res_base = 0;
    int count = 0;

    if (nbr > 0) {
        res_base = nbr / nbr_base;
        nbr = nbr % nbr_base;
        count_putnbr_base5(res_base, base);
        if (nbr >= 10 && nbr <= 15) {
            count++;
        }
    }
    return count;
}

static int function1(formats_t *formats, int count, int a, long long nb)
{
    if ((formats->flag1 == 1 || formats->flag2 == 1 || formats->flag3 == 1)
        && formats->flag1 != 8 && formats->flag2 != 8 && formats->flag3 != 8
        && formats->width != 0)
        a = a + 2;
    if (formats->width != 0 && (formats->flag1 != 8 && formats->flag2 != 8
            && formats->flag3 != 8) && (formats->flag1 != 4
            && formats->flag2 != 4 && formats->flag3 != 4
            && formats->precision == 0)) {
        for (a += count_putnbr_base5(nb, "0123456789ABCDEF") + 1;
            a < formats->width; a++) {
            my_putchar(' ');
            count++;
        }
    }
    return count;
}

static int function2(formats_t *formats, int count, int a, long long nb)
{
    if (formats->width != 0 && formats->precision != 0)
        a = a - 3;
    if (formats->width != 0 && formats->flag1 != 8 && formats->flag2 != 8
        && formats->flag3 != 8 && formats->flag1 != 4
        && formats->flag2 != 4 && formats->flag3 != 4
        && formats->precision != 0) {
        for (a += count_putnbr_base5(nb, "0123456789ABCDEF")
                + formats->precision + 2; a < formats->width; a++) {
            my_putchar(' ');
            count++;
        }
    }
    if (formats->flag1 == 1 || formats->flag2 == 1 || formats->flag3 == 1) {
        my_putstr("0X");
        count += 2;
    }
    return count;
}

static int function3(formats_t *formats, int count, int a, long long nb)
{
    if (formats->flag1 == 8 || formats->flag2 == 8 || formats->flag3 == 8) {
        if (formats->flag1 == 1 || formats->flag2 == 1 || formats->flag3 == 1)
            a = a + 2;
        for (a += count_putnbr_base5(nb, "0123456789ABCDEF") + 1;
            a < formats->width; a++) {
            my_putchar('0');
            count++;
        }
    }
    if (formats->precision != 0 && formats->width != 0 && formats->flag1 != 8
        && formats->flag2 != 8 && formats->flag3 != 8 && formats->flag1 != 4
        && formats->flag2 != 4 && formats->flag3 != 4) {
        for (a = count_putnbr_base5(nb, "0123456789ABCDEF") + 1;
            a < formats->precision; a++) {
            my_putchar('0');
            count++;
        }
    }
    return count;
}

int function6(formats_t *formats, int count, int a, long long nb)
{
    if (formats->precision != 0 && formats->width == 0 && formats->flag1 != 8
        && formats->flag2 != 8 && formats->flag3 != 8 && formats->flag1 != 4
        && formats->flag2 != 4 && formats->flag3 != 4) {
        for (int a = count_putnbr_base5(nb, "0123456789ABCDEF") + 1;
            a < formats->precision; a++) {
            my_putchar('0');
            count++;
        }
    }
    if (formats->precision != 0 && (formats->flag1 == 4 || formats->flag2 == 4
            || formats->flag3 == 4)) {
        for (int a = count_putnbr_base5(nb, "0123456789ABCDEF") + 1;
            a < formats->precision; a++) {
            my_putchar('0');
            count++;
        }
    }
    return count;
}

int function7(formats_t *formats, int count, int a, long long nb)
{
    if (nb == 0) {
        my_putchar('0');
        count++;
        return count;
    }
    count += function1(formats, count, a, nb);
    count += function2(formats, count, a, nb);
    count += function3(formats, count, a, nb);
    count += function6(formats, count, a, nb);
    count += my_putnbr_base5(nb, "0123456789ABCDEF");
    if (formats->flag1 == 4 || formats->flag2 == 4 || formats->flag3 == 4) {
        for (a = count_putnbr_base5(nb, "0123456789ABCDEF")
                + formats->precision + 1; a < formats->width; a++) {
            my_putchar(' ');
            count++;
        }
    }
    return count;
}

int specifier_bigx(va_list arguments_list, formats_t *formats)
{
    long long nb = 0;
    int count = 0;
    int a = 0;

    if (formats->length == 0 || formats->length == 1 || formats->length == 128)
        nb = va_arg(arguments_list, int);
    if (formats->length == 2)
        nb = va_arg(arguments_list, long);
    if (formats->length == 256)
        nb = va_arg(arguments_list, long long);
    if (formats->length == 16)
        nb = va_arg(arguments_list, long long);
    if (formats->length == 32)
        nb = va_arg(arguments_list, long long);
    if (nb == 0 && formats->point == 1) {
        return count;
    }
    count = function7(formats, count, a, nb);
    return count;
}
