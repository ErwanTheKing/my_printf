/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** fill_precision_struct
*/

#include "my.h"
#include "formats.h"

int fill_precision_struct(formats_t *formats,
    char const *main_str, int main_str_pos)
{
    int nb = 0;

    if (main_str[main_str_pos] == '.') {
        main_str_pos++;
        while (my_char_isnum(main_str[main_str_pos]) == 1) {
            nb = (nb * 10) + (main_str[main_str_pos] - 48);
            main_str_pos++;
        }
        formats->point = 1;
        formats->precision = nb;
        return main_str_pos;
    }
    formats->point = 0;
    formats->precision = 0;
    return main_str_pos;
}
