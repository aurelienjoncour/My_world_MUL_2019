/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task02
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int nb)
{
    int i = 0;

    while (i < nb && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}