/*
** EPITECH PROJECT, 2025
** islower
** File description:
** islower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z')
            return 0;
    }
    return 1;
}
