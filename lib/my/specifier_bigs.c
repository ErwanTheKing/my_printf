/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** The flag_S.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/formats.h"
#include "../../include/my.h"

int specifier_bigs(va_list arguments_list, formats_t *formats)
{
    char **str = va_arg(arguments_list, char **);

    my_show_word_array(str);
    return 0;
}
