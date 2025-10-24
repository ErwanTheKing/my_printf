/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** manage_spaces
*/

#include "formats.h"

void manage_spaces(formats_t *formats)
{
    if (formats->flag1 == 16 && formats->flag2 == 2)
        formats->flag1 = 2;
    if (formats->flag1 == 16 && formats->flag4 == 2
        || formats->flag1 == 16 && formats->flag5 == 2)
        formats->flag1 = 2;
    if (formats->flag2 == 16 && formats->flag4 == 2
        || formats->flag2 == 16 && formats->flag5 == 2)
        formats->flag2 = 2;
    if (formats->flag1 == 2 && formats->flag2 == 16)
        formats->flag2 = 0;
    if (formats->flag1 == 2 && formats->flag3 == 16)
        formats->flag3 = 0;
}
