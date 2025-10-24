/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** fill_format_struct
*/


#include "formats.h"
#include "my.h"

int fill_format_struct(formats_t *formats,
    char const *main_str, int main_str_pos)
{
    int many_flags = 0;

    for (; many_flags != 5; many_flags++) {
        main_str_pos = fill_flag_struct(formats, main_str, main_str_pos,
            many_flags);
    }
    main_str_pos = fill_flag_struct(formats, main_str, main_str_pos,
        many_flags);
    main_str_pos = fill_width_struct(formats, main_str, main_str_pos);
    main_str_pos = fill_precision_struct(formats, main_str, main_str_pos);
    main_str_pos = fill_length_struct(formats, main_str, main_str_pos);
    main_str_pos = fill_specifier_struct(formats, main_str, main_str_pos);
    manage_spaces(formats);
    manage_zeros(formats);
    return main_str_pos + 1;
}
