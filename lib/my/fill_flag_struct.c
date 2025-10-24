/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** fill_flag_struct
*/

#include <stdio.h>

#include "my.h"
#include "formats.h"

int fill_flag_struct(formats_t *formats,
    char const *main_str, int main_str_pos, int many_flags)
{
    char *const flags = "#+-0 ";
    int found = 0;

    for (int act_flag = 0; flags[act_flag] != '\0'; act_flag++) {
        if (many_flags == 0 && main_str[main_str_pos] == flags[act_flag])
            formats->flag1 = my_compute_power_rec(2, act_flag);
        if (many_flags == 1 && main_str[main_str_pos] == flags[act_flag])
            formats->flag2 = my_compute_power_rec(2, act_flag);
        if (many_flags == 2 && main_str[main_str_pos] == flags[act_flag])
            formats->flag3 = my_compute_power_rec(2, act_flag);
        if (many_flags == 3 && main_str[main_str_pos] == flags[act_flag])
            formats->flag4 = my_compute_power_rec(2, act_flag);
        if (main_str[main_str_pos] == flags[act_flag])
            found = 1;
    }
    if (found == 1)
        return main_str_pos + 1;
    return main_str_pos;
}
