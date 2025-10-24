/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** manage_zeros
*/

#include "formats.h"
#include "my.h"

void manage_zeros(formats_t *formats)
{
    if (formats->flag1 == 8 && formats->flag4 == 4
        || formats->flag1 == 8 && formats->flag5 == 4)
        formats->flag1 = 4;
    if (formats->flag2 == 8 && formats->flag4 == 4
        || formats->flag2 == 8 && formats->flag5 == 4)
        formats->flag2 = 4;
    if (formats->flag1 == 4 && formats->flag2 == 8)
        formats->flag2 = 0;
    if (formats->flag1 == 4 && formats->flag3 == 8)
        formats->flag3 = 0;
    erase_flags(formats);
}
