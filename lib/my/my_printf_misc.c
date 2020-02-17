/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf misc
*/

#include "my.h"
#include "my_printf.h"

int len_nbr(long long int nbr, int base)
{
    int len = 1;

    if (nbr < 1) {
        nbr = -nbr;
        len++;
    }
    while ((nbr / base) >= 1) {
        len++;
        nbr /= base;
    }
    return len;
}

int what_type(char spe)
{
    if (spe == 'd' || spe == 'i')
        return 1;
    if (spe == 'o' || spe == 'u' || spe == 'x' || spe == 'X' || spe == 'b')
        return 2;
    if (spe == 'p')
        return 3;
    if (spe == 'c')
        return 4;
    if (spe == 's' || spe == 'S')
        return 5;
    if (spe == '%')
        return 6;
    return 42;
}

void get_nbr_fromformat(char *format, int *i, int *nbr)
{
    *nbr = my_getnbr(&format[*i]);
    if (format[*i] == '.')
        (*i)++;
    while (is_digit(format[*i], 1))
        (*i)++;
}

int is_digit(char c, int len_nbr)
{
    if ((c > '0' && c <= '9') || (c == '0' && len_nbr > 0))
        return (1);
    return (0);
}

int strlen_spec(char *str, char type, int len)
{
    int i = -1;
    int length = 0;

    while (str[++i] != '\0' && (len == -1 || i < len)) {
        if ((str[i] >= 32 && str[i] <= 126) || type == 's')
            length++;
        else
            length += 4;
    }
    return length;
}
