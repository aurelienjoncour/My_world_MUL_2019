/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task18 [MODIFIED]
*/

#include "my.h"
#include <stdlib.h>

static int count_nbr_digit(int nb, int base)
{
    int len = 0;

    while (nb != 0) {
        nb /= base;
        len++;
    }
    return (len);
}

static char *base_conv(int nb, int base, char const *base_str, char *ret)
{
    int nb_digit = count_nbr_digit(nb, base);
    int *digit = malloc(sizeof(int) * (nb_digit));
    int i_digita = 0;
    int i_digitb = 0;

    while (nb != 0) {
        digit[i_digita++] = (nb % base);
        nb /= base;
    }
    if (ret[0] == '-') {
        i_digitb++;
    }
    for (int j = (nb_digit - 1); j >= 0; j--) {
        ret[i_digitb++] = base_str[digit[j]];
    }
    free(digit);
    return (ret);
}

static char *allocate_memory(int base, int *nbr)
{
    int nb_digit = count_nbr_digit(*nbr, base);
    char *ret;

    if (*nbr < 0) {
        ret = malloc(sizeof(char) * (nb_digit + 2));
        ret[0] = '-';
        *nbr = (-(*nbr));
        ret[nb_digit + 1] = '\0';
    } else {
        ret = malloc(sizeof(char) * (nb_digit + 1));
        ret[0] = '0';
        ret[nb_digit] = '\0';
    }
    return (ret);
}

char *my_putnbr_base_str(int nbr, char const *base)
{
    int len_base = my_strlen(base);
    char *ret = allocate_memory(len_base, &nbr);

    if (nbr == 0) {
        free(ret);
        return my_strdup("0");
    }
    return (base_conv(nbr, len_base, base, ret));
}
