/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Task04
*/

int my_compute_power_rec(int nb, int p)
{
    int result = 1;

    if (nb < 0 && p % 2 == 0)
        nb = (-nb);
    if (p > 1) {
        result = my_compute_power_rec(nb, (p - 1));
    } else if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    if (nb > 0 && (result * nb) <= result) {
        return (0);
    }
    return (result * nb);
}
