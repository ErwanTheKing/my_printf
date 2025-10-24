/*
** EPITECH PROJECT, 2025
** my_putchar_printf
** File description:
** putchar for printf
*/

#include <unistd.h>
#include <stdarg.h>

#include "my.h"
#include "../../include/formats.h"

int specifier_c(va_list arguments_list, formats_t *formats)
{
    int c = va_arg(arguments_list, int);

    if (formats->width != 0 && formats->flag1 == 8
        || formats->width != 0 && formats->flag1 == 0) {
        for (int i = 0; i < (formats->width - 1); i++) {
            my_putchar(' ');
        }
        write(1, &c, 1);
    }
    if (formats->width != 0 && formats->flag1 == 4) {
        write(1, &c, 1);
        for (int i = 0; i < (formats->width - 1); i++) {
            my_putchar(' ');
        }
    }
    if (formats->width == 0 && formats->flag1 == 0) {
        write(1, &c, 1);
    }
    return 1;
}
