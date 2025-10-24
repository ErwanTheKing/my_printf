/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** it's a function that displays the characters
*/

#include "my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
