/*
** EPITECH PROJECT, 2025
** my_showstr
** File description:
** showstr
*/

int my_char_isprintable(char c)
{
    if (c < '!' || c > '~')
        return 0;
    return 1;
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isprintable(str[i]) == 0) {
            return 0;
        }
        return 0;
    }
    return 0;
}
