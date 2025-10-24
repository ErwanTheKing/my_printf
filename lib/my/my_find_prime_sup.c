/*
** EPITECH PROJECT, 2025
** my_find_prime_sup
** File description:
** a function that returns the smallest prime number
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int a = nb;

    if (nb <= 1)
        return (2);
    while (my_is_prime(a) != 1) {
        a++;
    }
    return (a);
}
