/*
** EPITECH PROJECT, 2019
** 102architech_2019
** File description:
** extract the number in a parameter (check error)
*/

#include "102architect.h"

static int is_digit(char c, int len_nbr)
{
    if ((c > '0' && c <= '9') || (c == '0' && len_nbr > 0))
        return (1);
    return (0);
}

static void incr_len(unsigned int *len, char c, char after_dot)
{
    if (is_digit(c, len[0])) {
        len[0]++;
    } else if (c != '.' && c != '0' && c != '-') {
        my_putstr_error(ERR_ARG);
        exit(84);
    }
    if (is_digit(c, len[1]) && after_dot == 0)
        len[1]++;
    else if (is_digit(c, 1) && after_dot == 1)
        len[2]++;
}

static unsigned int *len_nbr(char *nbr)
{
    unsigned int *len = malloc(sizeof(unsigned int) * 3);
    int i = -1;
    char after_dot = 0;
    int zero_counter = 0;

    len[0] = 0;
    len[1] = 0;
    len[2] = 0;
    while (nbr[++i] != '\0') {
        if (nbr[i] == '.')
            after_dot = 1;
        if (nbr[i] == '0')
            zero_counter++;
        incr_len(len, nbr[i], after_dot);
    }
    if (len[0] == 0 && zero_counter > 0)
        len[0] = 1;
    return (len);
}

static char *get_dot(char *nbr)
{
    int i = -1;

    while (nbr[++i] != '\0') {
        if (nbr[i] == '.')
            return (&nbr[i]);
    }
    return NULL;
}

double my_get_double(char *nbr)
{
    unsigned int *len = len_nbr(nbr);
    char *dot = get_dot(nbr);
    double alpha = 0;
    double beta = 0;

    if (len[0] == 0 || len[0] > 39) {
        my_putstr_error(ERR_ARG);
        exit(84);
    }
    if (dot == NULL || len[2] == 0) {
        free(len);
        return ((double)my_getnbr(nbr));
    }
    if (len[1] != 0)
        alpha = my_getnbr(nbr);
    beta = (double)my_getnbr(dot) / my_compute_power_rec(10, len[2]);
    if (alpha < 0 || (nbr[0] == '-' && alpha == 0))
        beta = -beta;
    free(len);
    return (alpha + beta);
}
