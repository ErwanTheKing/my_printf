/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** fill_lenght_struct
*/

#include "my.h"
#include "formats.h"

int fill_length_struct(formats_t *formats,
    char const *main_str, int main_str_pos)
{
    char *const length = "hlqLjzt";

    if (main_str[main_str_pos] == 'h'
        && main_str[main_str_pos + 1] == 'h') {
        formats->length = 128;
        return main_str_pos + 2;
    }
    if (main_str[main_str_pos] == 'l'
        && main_str[main_str_pos + 1] == 'l') {
        formats->length = 256;
        return main_str_pos + 2;
    }
    for (int act_length = 0; length[act_length] != '\0'; act_length++) {
        if (main_str[main_str_pos] == length[act_length]) {
            formats->length = my_compute_power_rec(2, act_length);
            return main_str_pos + 1;
        }
    }
    formats->length = 0;
    return main_str_pos;
}
