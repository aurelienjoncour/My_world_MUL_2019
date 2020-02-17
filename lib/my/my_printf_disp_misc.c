/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf display
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

int define_len_space(arg_t *arg, long long int data, int base)
{
    int len_flags = 0;
    int space = -1;

    if (arg->flags[0] == '#' && arg->spec[0] != 'o')
        len_flags += 2;
    if (arg->flags[0] == '#' && arg->spec[0] == 'o')
        len_flags++;
    if (arg->flags[3] == ' ' || arg->flags[4] == '+')
        len_flags++;
    space = arg->width - len_flags;
    space -= len_nbr(data, base);
    if (space < 0)
        space = 0;
    return space;
}

int define_len_preci(arg_t *arg, long long int data, int base)
{
    int zero = -1;

    zero = arg->precision;
    zero -= len_nbr(data, base);
    if (arg->flags[0] == '#' && arg->spec[0] == 'o')
        zero--;
    if (zero < 0)
        zero = 0;
    return zero;
}

int disp_zeros(char flag_zero, int len_space, int len_preci)
{
    if (flag_zero == '0') {
        for (int i = 0; i < len_space; i++)
            my_putchar('0');
        return len_space;
    }
    if (len_preci > 0) {
        for (int i = 0; i < len_preci; i++)
            my_putchar('0');
        return len_preci;
    }
    return 0;
}

int disp_width(int len_space, int len_preci)
{
    for (int i = 0; i < len_space - len_preci; i++)
        my_putchar(' ');
    if (len_space - len_preci >= 0)
        return (len_space - len_preci);
    return 0;
}

int disp_not_printable_char(char c)
{
    int len_nb = len_nbr(c, 8);

    my_putchar('\\');
    for (int i = 0; i < 3 - len_nb; i++)
        my_putchar('0');
    my_putnbr_base(c, "01234567");
    return 4;
}
