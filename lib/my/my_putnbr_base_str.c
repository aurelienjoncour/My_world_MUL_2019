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
    int len_res = count_nbr_digit(nb, base);
    int *res = malloc(sizeof(int) * len_res);
    int i = 0;
    int k = 0;

    if (ret[0] == '-') {
        i++;
        k++;
    }
    while (nb != 0) {
        res[i++] = (nb % base);
        nb /= base;
    }
    for (int j = (i - 1); j >= 0; j--)
        ret[k++] = base_str[res[j]];
    free(res);
    return (ret);
}

static char *allocate_memory(int base, int *nbr)
{
    int len_ret = count_nbr_digit(*nbr, base);
    char *ret;

    if (*nbr < 0) {
        ret = malloc(sizeof(char) * (len_ret + 2));
        ret[0] = '-';
        *nbr = (-(*nbr));
        ret[len_ret + 1] = '\0';
    } else {
        ret = malloc(sizeof(char) * (len_ret + 1));
        ret[len_ret] = '\0';
    }
    return (ret);
}

char *my_putnbr_base_str(int nbr, char const *base)
{
    int len_base = my_strlen(base);
    char *ret = allocate_memory(len_base, &nbr);

    return (base_conv(nbr, len_base, base, ret));
}
