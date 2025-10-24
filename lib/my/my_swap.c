/*
** EPITECH PROJECT, 2025
** my_swap
** File description:
** it's a function to swap the  content
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
