/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Task07
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int pr = nb;

    while (my_is_prime(pr) == 0) {
        if (pr == 2147483647)
            return (0);
        pr++;
    }
    return (pr);
}
