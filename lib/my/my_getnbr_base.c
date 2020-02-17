/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** task19
*/

#include "my.h"

static int count_neg(char const *str)
{
    int i = 0;
    int neg = 0;

    while (str[i] < '0') {
        if (str[i] == '-')
            neg++;
        i++;
    }
    return (neg);
}

static int conv_str(char const *str, int istr, int start, int ibase)
{
    int nb = 0;
    int char_nb;

    for (int i = (istr - 1); i >= 0; i--) {
        if (str[istr - i - 1] < 'A')
            char_nb = str[istr - i - 1 + start] - '0';
        else
            char_nb = str[istr - i - 1 + start] - 'A' + 10;
        nb += my_power_rec(ibase, i) * char_nb;
    }
    return (nb);
}

int my_getnbr_base(char const *str, char const *base)
{
    int ibase = 0;
    int istr = 0;
    int neg = 0;
    int nb_start = 0;

    while (base[ibase] != '\0')
        ibase++;
    while (str[istr] != '\0')
        istr++;
    while (str[nb_start] < '0' || str[nb_start] != '\0')
        nb_start++;
    if (nb_start == istr || istr == 0)
        return (0);
    neg = count_neg(str);
    istr -= nb_start;
    if (neg % 2 != 0)
        return (-conv_str(str, istr, nb_start, ibase));
    else
        return (conv_str(str, istr, nb_start, ibase));
}
