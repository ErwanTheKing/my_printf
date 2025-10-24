/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** The my_char_is_specifier.c
*/

int my_char_is_specifier(char c)
{
    char *flags = "diouxXeEfFgGaAcspnm%SbB";

    for (int i = 0; flags[i] != '\0'; i++) {
        if (c == flags[i])
            return 1;
    }
    return 0;
}
