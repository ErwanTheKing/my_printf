/*
** EPITECH PROJECT, 2025
** my_strcomp
** File description:
** comp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    return (s1[i] - s2[i]);
}
