/*
** EPITECH PROJECT, 2025
** my_strncomp
** File description:
** n comp
*/

#include <stdio.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0)
        return 0;
    while (i != n && s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    return (s1[i] - s2[i]);
}
