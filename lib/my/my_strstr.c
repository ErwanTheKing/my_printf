/*
** EPITECH PROJECT, 2025
** my_strstr
** File description:
** strstr
*/

#include <stdio.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    int x = 0;
    char *c = {0};

    while (str[i] != '\0')
        i++;
    while (to_find[x] != '\0')
        x++;
    i--;
    x--;
    while (j < i) {
        if (my_strncmp(str + j, to_find, x) == 0)
            return (str + j);
        else
            j++;
    }
    return (c);
}
