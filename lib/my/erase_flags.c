/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** rease_flags
*/

#include "formats.h"

void erase_flags(formats_t *formats)
{
    if (formats->flag1 == 8 && formats->precision != 0) {
        formats->flag5 = 8;
        formats->flag1 = formats->flag2;
        formats->flag2 = 0;
    }
    if (formats->flag2 == 8 && formats->precision != 0) {
        formats->flag5 = 8;
        formats->flag2 = 0;
    }
    if (formats->flag1 == 2 && formats->flag2 == 4)
        formats->flag2 = 0;
}
