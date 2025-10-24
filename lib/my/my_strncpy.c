/*
** EPITECH PROJECT, 2025
** my_strncpy
** File description:
** n copy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (i < n)
        dest[i] = '\0';
    return (dest);
}
