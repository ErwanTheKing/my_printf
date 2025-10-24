/*
** EPITECH PROJECT, 2025
** strcat
** File description:
** cat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int a = my_strlen(dest);
    int b = my_strlen(src);
    int c = a + b;
    int d = 0;

    while (a <= c) {
        dest[a] = src[d];
        a++;
        d++;
    }
    return (dest);
}
