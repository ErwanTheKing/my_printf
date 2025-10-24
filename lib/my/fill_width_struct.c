/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** fill_width_struct
*/

#include "my.h"
#include "formats.h"

int fill_width_struct(formats_t *formats,
    char const *main_str, int main_str_pos)
{
    int nb = 0;

    if (my_char_isnum(main_str[main_str_pos]) == 1) {
        while (main_str[main_str_pos] != '.'
            && my_char_is_specifier(main_str[main_str_pos]) == 0) {
            nb = (nb * 10) + (main_str[main_str_pos] - 48);
            main_str_pos++;
        }
        formats->width = nb;
        return main_str_pos;
    }
    formats->width = 0;
    return main_str_pos;
}
