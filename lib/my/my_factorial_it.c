/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Task01
*/

int my_factorial_it(int nb)
{
    int result = 1;

    if (nb < 0 || nb > 12)
        return (0);
    for (int i = 1; i <= nb; i++) {
        result *= i;
    }
    return (result);
}
