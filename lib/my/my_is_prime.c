/*
** EPITECH PROJECT, 2025
** my_is_prime
** File description:
** it's a function that return 1 or 2
*/

int my_is_prime(int nb)
{
    int a = nb;
    int b;
    int count = 0;

    if (nb <= 1)
        return (0);
    while (a >= 1) {
        if ((nb % a) == 0) {
            a--;
            count++;
        } else
            a--;
    }
    if (count == 2) {
        return (1);
    } else
        return (0);
}
