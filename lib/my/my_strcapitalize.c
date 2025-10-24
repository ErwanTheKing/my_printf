/*
** EPITECH PROJECT, 2025
** strcapitalize
** File description:
** capitalize
*/

#include <stdio.h>
#include "my.h"

static char upper(char a)
{
    if (a >= 'a' && a <= 'z')
        a = a - 32;
    return a;
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    str = my_strlowcase(str);
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = upper(str[0]);
    }
    for (; str[i] != '\0'; i++) {
        if (str[i - 1] == ' ' || str[i - 1] == '-' || str[i - 1] == '+')
            str[i] = upper(str[i]);
    }
    return (str);
}
