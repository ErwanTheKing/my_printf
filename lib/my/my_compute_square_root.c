/*
** EPITECH PROJECT, 2025
** my_compute_square_root
** File description:
** function to return the square root
*/

int my_compute_square_root(int nb)
{
    int a = nb;

    if (nb < 0)
        return (0);
    while ((a * a) != nb) {
        if (a < 0)
            return (0);
        else
            a--;
    }
    return (a);
}
