/*
** EPITECH PROJECT, 2025
** isalpha
** File description:
** isalpha
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            return 0;
    }
    return 1;
}
