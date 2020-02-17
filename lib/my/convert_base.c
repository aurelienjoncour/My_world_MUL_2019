/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** Task05
*/

#include "my.h"

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int nb = 42;
    char *str;

    nb = my_getnbr_base(nbr, base_from);
    str = my_putnbr_base_str(nb, base_to);
    return (str);
}
