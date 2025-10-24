/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int j;

    for (j = 0; src[j] != '\0'; j++) {
        dest[j] = src[j];
    }
    dest[j] = '\0';
    return (dest);
}
