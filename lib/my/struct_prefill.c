/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** struct_prefill
*/

#include "formats.h"

void struct_prefill(formats_t *formats)
{
    formats->trigger = '%';
    formats->specifier = 0;
    formats->flag1 = 0;
    formats->flag2 = 0;
    formats->flag3 = 0;
}
