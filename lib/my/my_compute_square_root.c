/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Task05
*/

#include <stdio.h>

int my_compute_square_root(int nb)
{
    int result = 1;

    if (nb <= 0)
        return (0);
    while ((result * result) < nb && result <= 46340) {
        result++;
    }
    if ((result * result) != nb)
        return (0);
    return (result);
}
