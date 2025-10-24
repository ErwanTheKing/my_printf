/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** fill_specifier_struct
*/


#include <unistd.h>

#include "my.h"
#include "formats.h"

int fill_specifier_struct(formats_t *formats,
    char const *main_str, int main_str_pos)
{
    char *const specifier = "diouxXeEfFgGaAcspnm%SbB";

    for (int act_specifier = 0; specifier[act_specifier] != '\0';
        act_specifier++) {
        if (main_str[main_str_pos] == specifier[act_specifier]) {
            formats->specifier = specifier[act_specifier];
            return main_str_pos;
        }
    }
    formats->specifier = 0;
    write(2, "this specifier does not exist", 29);
    return main_str_pos - 1;
}
