/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strndup
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup(char const *src, int n)
{
    char *str;

    str = malloc(sizeof(char) * (n + 1));
    if (str == NULL)
        return NULL;
    return my_strncpy(str, src, n);
}