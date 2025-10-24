/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** The flag_%.c
*/

#include <stdarg.h>
#include "../../include/formats.h"
#include "../../include/my.h"

int specifier_po(formats_t *formats)
{
    int count = 0;

    if (formats->specifier == '%') {
        my_putchar('%');
        count++;
    }
    return count;
}
