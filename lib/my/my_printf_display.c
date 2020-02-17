/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf display
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

static int (* const types[13])(arg_t *arg, va_list *ap) =
{
    &disp_int,
    &disp_uint_x_x,
    &disp_uint_o,
    &disp_uint_b,
    &disp_uint_u,
    &disp_char,
    &disp_str,
    &disp_uint_p,
    &disp_l_llq,
    &disp_ul_ullq,
    &disp_short,
    &disp_ushort,
    &disp_uint_lx
};

static int display_if_invalid_arg(arg_t *arg, char *ptrformat)
{
    int i = 0;

    if (arg->spec[0] != '.')
        return 0;
    while (*(ptrformat - i) != '%')
        i++;
    for (int j = 0; j <= i; j++)
        my_putchar(*(ptrformat - (i - j)));
    return (i + 1);
}

static void display_arg_ext2(arg_t *arg, va_list *ap, int *len)
{
    if (arg->spec[0] == 'c' || arg->length[1] == 'h')
        *len = types[5](arg, ap);
    if (what_type(arg->spec[0]) == 1 && arg->length[0] != 'h')
        *len = types[0](arg, ap);
    if (arg->spec[0] == 'x' || arg->spec[0] == 'X')
        *len = types[1](arg, ap);
    if (arg->spec[0] == 'o')
        *len = types[2](arg, ap);
    if (arg->spec[0] == 'b')
        *len = types[3](arg, ap);
    if (arg->spec[0] == 'u')
        *len = types[4](arg, ap);
    if (arg->spec[0] == 's' || arg->spec[0] == 'S')
        *len = types[6](arg, ap);
    if (arg->spec[0] == 'p')
        *len = types[7](arg, ap);
}

static void display_arg_ext1(arg_t *arg, va_list *ap, int *len)
{
    if (what_type(arg->spec[0]) == 1) {
        if (arg->length[0] == 'l' || arg->length[0] == 'q') {
            *len = types[8](arg, ap);
        }
    }
    if (what_type(arg->spec[0]) == 2) {
        if (arg->spec[0] == 'x' || arg->spec[0] == 'X') {
            *len = types[12](arg, ap);
        } else if (arg->length[0] == 'l' || arg->length[0] == 'q') {
            *len = types[9](arg, ap);
        }
    }
    if (what_type(arg->spec[0]) != 2 && my_strcmp(arg->length, "h") == 0)
        *len = types[10](arg, ap);
    if (what_type(arg->spec[0]) == 2 && my_strcmp(arg->length, "h") == 0)
        *len = types[11](arg, ap);
}

int display_arg(arg_t *arg, va_list *ap, char *ptrformat)
{
    int len = 0;

    len = display_if_invalid_arg(arg, ptrformat);
    clean_flags(arg);
    if (arg->spec[0] == '%') {
        my_putchar('%');
        len = 1;
    } else if (arg->spec[0] != '.') {
        display_arg_ext1(arg, ap, &len);
        if (len == 0)
            display_arg_ext2(arg, ap, &len);
    }
    return len;
}

int disp_llq_ext(arg_t *arg, long long int *data, int len_space, int len_preci)
{
    int len_wrote = 0;

    if (arg->flags[3] == ' ' && *data != 0)
        len_wrote += my_putchar(' ');
    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        len_wrote += disp_width(len_space, len_preci);
    if (arg->flags[4] == '+' && *data >= 0)
        len_wrote += my_putchar('+');
    return len_wrote;
}
