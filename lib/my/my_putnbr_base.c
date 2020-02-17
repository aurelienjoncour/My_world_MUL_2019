/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task18
*/

#include <unistd.h>

static int base_conv(long int nb, long int base, char const *basestr)
{
    long int res[100];
    int i = 0;

    while (nb != 0) {
        res[i++] = (nb % base);
        nb /= base;
    }
    for (int j = (i - 1); j >= 0; j--) {
        write(1, &basestr[res[j]], 1);
    }
    return i;
}

int my_putnbr_base(long int nbr, char const *base)
{
    long int nb_char = 0;
    int len_wrote = 0;

    if (nbr < 0) {
        write(1, "-", 1);
        nbr = (-nbr);
        len_wrote++;
    }
    while (base[nb_char] != '\0')
        nb_char++;
    len_wrote += base_conv(nbr, nb_char, base);
    return len_wrote;
}
