/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** The len_nbr.c
*/

long long len_nb(long long nb)
{
    int count = 0;

    if (nb < 0)
        nb = nb * -1;
    for (; nb > 0; count++)
        nb = nb / 10;
    return count;
}
