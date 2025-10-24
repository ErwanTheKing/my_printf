/*
** EPITECH PROJECT, 2025
** strndup
** File description:
** strndup
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup(char const *src, int n)
{
    int i = n + 1;
    char *dest;

    dest = malloc(sizeof(char) * (i));
    my_strncpy(dest, src, n);
    dest[n] = '\0';
    return (dest);
}
