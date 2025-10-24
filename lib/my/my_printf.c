/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "formats.h"

int put_word(char const *main_str, int main_str_pos)
{
    my_putchar(main_str[main_str_pos]);
    main_str_pos++;
    return main_str_pos;
}

int my_printf(char const *main_str, ...)
{
    va_list arg_list;
    formats_t *formats = malloc(sizeof(formats_t));
    int counter = 0;

    struct_prefill(formats);
    va_start(arg_list, main_str);
    for (int main_str_pos = 0; main_str[main_str_pos] != '\0';) {
        if (main_str[main_str_pos] != formats->trigger) {
            main_str_pos = put_word(main_str, main_str_pos);
            counter++;
        } else {
            main_str_pos++;
            main_str_pos = fill_format_struct(formats, main_str, main_str_pos);
            counter += is_specifier(arg_list, counter, formats);
            struct_prefill(formats);
        }
    }
    free(formats);
    va_end(arg_list);
    return counter;
}
