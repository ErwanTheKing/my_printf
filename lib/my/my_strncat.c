/*
** EPITECH PROJECT, 2025
** strncat
** File description:
** ncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int a = my_strlen(dest);
    int b = nb - 1;
    int c = a + b;
    int d = 0;

    while (a <= c) {
        dest[a] = src[d];
        a++;
        d++;
    }
    return (dest);
}
