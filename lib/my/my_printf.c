/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

static arg_t analyse_arg(char *format, int *i)
{
    arg_t arg = {".....", -1, -1, "..", "."};

    search_flags(format, i, &arg);
    if (is_digit(format[*i], 0) == 1)
        get_nbr_fromformat(format, i, &(arg.width));
    if (format[*i] == '.')
        get_nbr_fromformat(format, i, &(arg.precision));
    search_length(format, i, arg.length);
    search_specifier(format, i, arg.spec);
    return arg;
}

void clean_flags(arg_t *arg)
{
    if (arg->spec[0] == '%')
        my_strcpy(arg->flags, ".....");
    if (arg->flags[1] == '0' && (arg->flags[2] == '-' || arg->precision != -1))
        arg->flags[1] = '.';
    if (arg->flags[3] == ' ') {
        if (arg->flags[4] == '+')
            arg->flags[3] = '.';
        if (what_type(arg->spec[0]) != 1 && what_type(arg->spec[0]) != 3)
            arg->flags[3] = '.';
    }
    if (arg->flags[4] == '+') {
        if (what_type(arg->spec[0]) != 1 && what_type(arg->spec[0]) != 3)
            arg->flags[4] = '.';
    }
    if (arg->flags[1] == '0' && what_type(arg->spec[0]) > 2)
        arg->flags[1] = '.';
    if (arg->flags[0] == '#' && what_type(arg->spec[0]) != 2)
        arg->flags[0] = '.';
}

int my_printf(char *format, ...)
{
    int i = -1;
    int len = 0;
    arg_t arg;
    va_list ap;

    va_start(ap, format);
    while (format[++i] != '\0') {
        if (format[i] == '%') {
            i++;
            arg = analyse_arg(format, &i);
            len += display_arg(&arg, &ap, &format[i]);
        } else {
            my_putchar(format[i]);
            len++;
        }
    }
    va_end(ap);
    return len;
}
