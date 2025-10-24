/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** it's a function that displays the characters
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/formats.h"

int no_width(formats_t *formats, char *str)
{
    if (formats->width != 0 && formats->flag1 == 0 && formats->precision == 0) {
        for (int i = 0; i < (formats->width - my_strlen(str)); i++)
            my_putchar(' ');
        my_putstr(str);
        return formats->width;
    }
    if (formats->width == 0 && formats->flag1 != 4 && formats->point == 0) {
        my_putstr(str);
    }
    return 0;
}

int heres_point(formats_t *formats, const char *str)
{
    if (formats->flag1 == 0 && formats->point == 1 && formats->width != 0
        && formats->precision != 0) {
        for (int i =0; i < (formats->width - formats->precision); i++)
            my_putchar(' ');
        for (int i =0; i < formats->precision; i++)
            my_putchar(str[i]);
        return formats->width;
    }
    if (formats->point == 1 && formats->precision == 0)
        return 0;
    if (formats->point == 1 && formats->flag1 == 4 && formats->width != 0) {
        for (int i =0; i < formats->precision; i++)
            my_putchar(str[i]);
        for (int i =0; i < formats->width - formats->precision; i++)
            my_putchar(' ');
        formats->flag1 = 0;
        return formats->width;
    }
    return 0;
}

int specifier_s(va_list arguments_list, formats_t *formats)
{
    char *str = va_arg(arguments_list, char *);
    int i = 0;
    int final = 0;

    if (formats->precision != 0 && formats->width == 0) {
        for (int i =0; i < formats->precision; i++)
            my_putchar(str[i]);
        return i;
    }
    if (formats->flag1 == 4 && formats->precision == 0) {
        my_putstr(str);
        for (int i = 0; i < (formats->width - my_strlen(str)); i++)
            my_putchar(' ');
        return formats->width;
    }
    final += no_width(formats, str);
    final += heres_point(formats, str);
    return final;
}
