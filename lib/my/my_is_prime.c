/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Task06
*/

static int my_square_about(int nb);

int my_is_prime(int nb)
{
    int sqrt_nb = my_square_about(nb);

    if (nb < 2)
        return (0);
    for (int div = 2; div <= sqrt_nb; div++) {
        if (nb % div == 0 && nb != div) {
            return (0);
        }
    }
    return (1);
}

static int my_square_about(int nb)
{
    int result = 1;

    while ((result * result) < nb && result <= 46340)
        result++;
    return (result);
}
