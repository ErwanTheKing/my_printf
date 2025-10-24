/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** The flag_m.c
*/

#include <stdarg.h>
#include "../../include/formats.h"
#include "../../include/my.h"
#include <unistd.h>

int specifier_m(va_list arguments_list, formats_t *formats)
{
    char *str = va_arg(arguments_list, char *);
    int len = my_strlen(str);

    write(2, str, len);
    return 0;
}
