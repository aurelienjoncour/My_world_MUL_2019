/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** Task01
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *cpy = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (cpy == NULL)
        return (cpy);
    return (my_strcpy(cpy, src));
}
