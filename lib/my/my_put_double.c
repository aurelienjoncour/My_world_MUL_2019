/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** display a floating number
*/

#include <math.h>
#include "my.h"

static void display_decimal_digits(double decimal, int *decimal_len,
int nb_decimal)
{
    if (decimal < 10 && decimal != 0) {
        my_putchar('0');
        (*decimal_len)++;
    }
    if (decimal != 0)
        my_put_nbr(decimal);
    for (int i = (nb_decimal - *decimal_len); i > 0; i--)
        my_putchar('0');
}

static double calc_decimal(double nb, int nb_decimal)
{
    double integer = floor(nb);
    double decimal;

    if (nb < 0)
        integer = ceil(nb);
    decimal = round( (nb - integer) * pow(10, nb_decimal) );
    if (decimal < 0)
        decimal = -decimal;
    if (decimal == 100)
        decimal = -1;
    return decimal;
}

void my_put_double(double nb, int nb_decimal)
{
    double decimal = calc_decimal(nb, nb_decimal);
    int decimal_len = 0;

    if (nb < 0 && nb > -1)
        my_putchar('-');
    if (decimal == -1)
        my_put_nbr(round(nb));
    else
        my_put_nbr(nb);
    my_putchar('.');
    if (decimal < 1) {
        decimal_len = 0;
    } else {
        while (decimal / my_compute_power_rec(10, decimal_len) >= 1)
            decimal_len++;
    }
    if (decimal == -1)
        decimal = 0;
    display_decimal_digits(decimal, &decimal_len, nb_decimal);
}
