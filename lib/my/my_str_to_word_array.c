/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdlib.h>

static int my_str_isalphanum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9'))
        return (1);
    else
        return (0);
}

static int count_word(char const *str)
{
    int j;
    int b = 1;
    int count_word = 0;

    for (j = 0; str[j] != 0; j++) {
        if (my_str_isalphanum(str[j]) == 1 && b == 1) {
            b = 0;
            count_word++;
        }
        if (my_str_isalphanum(str[j]) == 0 && b == 0)
            b = 1;
    }
    return (count_word);
}

static int count_decalage(char const *str, int a)
{
    int x = 1;

    while (my_str_isalphanum(str[a + x]) == 0 && str[a + x] != '\0') {
        x++;
    }
    return (x);
}

static char **finish(char const *str, char **dest)
{
    int count = 0;
    int x;

    for (int a = 0; str[a] != '\0'; a++) {
        if (my_str_isalphanum(str[a + 1]) == 0
            && my_str_isalphanum(str[a]) == 1) {
            dest[count] = my_strndup(str, a + 1);
            count++;
            x = count_decalage(str, a);
            str = str + a + x;
            a = -1;
            x = 0;
        }
    }
    return (dest);
}

char **my_str_to_word_array(char const *str)
{
    char **str2;
    int j;
    int count = 0;
    int x;
    int l;

    j = count_word(str);
    str2 = malloc(sizeof(char *) * (j + 1));
    for (l = 0; my_str_isalphanum(str[l]) == 0; l++);
    str = str + l;
    str2 = finish(str, str2);
    str2[j] = NULL;
    return (str2);
}
