/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** File 2 : display arg
*/

#include "my_printf.h"
#include "my.h"

int disp_short(arg_t *arg, va_list *ap)
{
    short int data = va_arg(*ap, int);
    int len_space = define_len_space(arg, (long long int)data, 10);
    int len_preci = define_len_preci(arg, (long long int)data, 10);
    int len_wrote = 0;

    if (arg->flags[3] == ' ' && data != 0)
        len_wrote += my_putchar(' ');
    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        len_wrote += disp_width(len_space, len_preci);
    if (arg->flags[4] == '+' && data >= 0)
        len_wrote += my_putchar('+');
    len_wrote += disp_zeros(arg->flags[1], len_space, len_preci);
    len_wrote += my_put_nbr(data);
    if (arg->flags[2] == '-')
        len_wrote += disp_width(len_space, len_preci);
    return len_wrote;
}

int disp_ushort(arg_t *arg, va_list *ap)
{
    unsigned short int data = va_arg(*ap, unsigned int);
    int len_space = define_len_space(arg, (long long int)data, 10);
    int len_preci = define_len_preci(arg, (long long int)data, 10);
    int len_wrote = 0;

    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        len_wrote += disp_width(len_space, len_preci);
    if (arg->flags[0] == '#' && arg->spec[0] == 'o' && data != 0)
        len_wrote += my_putstr("0");
    len_wrote += disp_zeros(arg->flags[1], len_space, len_preci);
    len_wrote += my_put_nbr(data);
    if (arg->flags[2] == '-')
        len_wrote += disp_width(len_space, len_preci);
    return len_wrote;
}

int disp_uint_lx(arg_t *arg, va_list *ap)
{
    unsigned long int data = va_arg(*ap, unsigned long int);
    int len_space = define_len_space(arg, (long long int)data, 16);
    int len_preci = define_len_preci(arg, (long long int)data, 16);
    int len_wrote = 0;

    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        len_wrote += disp_width(len_space, len_preci);
    if (arg->flags[0] == '#' && arg->spec[0] == 'x' && data != 0)
        len_wrote += my_putstr("0x");
    if (arg->flags[0] == '#' && arg->spec[0] == 'X' && data != 0)
        len_wrote += my_putstr("0X");
    len_wrote += disp_zeros(arg->flags[1], len_space, len_preci);
    if (arg->spec[0] == 'x')
        len_wrote += my_putnbr_base(data, "0123456789abcdef");
    else if (arg->spec[0] == 'X')
        len_wrote += my_putnbr_base(data, "0123456789ABCDEF");
    if (arg->flags[2] == '-')
        len_wrote += disp_width(len_space, len_preci);
    return len_wrote;
}
