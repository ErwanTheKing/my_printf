/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** is_specifier
*/

#include <stdarg.h>
#include "my.h"
#include "formats.h"
#include <stdio.h>

int is_specifier(va_list arguments_list, int counter, formats_t *formats)
{
    char *const specifier = "diouxXeEfFgGaAcspnmSbB";
    int (*fcall[])(va_list, formats_t *) = {specifier_di, specifier_di,
        specifier_o, specifier_u, specifier_x, specifier_bigx, specifier_e,
        specifier_bige, specifier_fbigf, specifier_fbigf, specifier_g,
        specifier_bigg, specifier_a, specifier_biga, specifier_c, specifier_s,
        specifier_p, specifier_n, specifier_m, specifier_bigs, specifier_b,
        specifier_bigb};

    erase_flags(formats);
    for (int arg_type = 0; specifier[arg_type] != '\0'; arg_type++) {
        if (specifier[arg_type] == formats->specifier) {
            counter = fcall[arg_type](arguments_list, formats);
        }
    }
    if (formats->specifier == '%') {
        counter += specifier_po(formats);
    }
    return counter;
}
