/*
** EPITECH PROJECT, 2025
** strdup
** File description:
** strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i = my_strlen(src);
    char *dest;

    dest = malloc(sizeof(char) * (i + 1));
    my_strcpy(dest, src);
    return (dest);
}
