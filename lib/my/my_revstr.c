/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** rev str
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char a;
    int count = 0;

    while (str[i] != '\0')
        i++;
    i--;
    while (j < i) {
        a = str[j];
        str[j] = str[i];
        str[i] = a;
        j++;
        i--;
    }
    return (str);
}
