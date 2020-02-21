/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** tool function
*/

#include "my_world.h"

char *my_str_concat(const char *stra, const char *strb)
{
    int len = 0;
    char *result = NULL;

    if (!stra || !strb)
        return NULL;
    len = my_strlen(stra) + my_strlen(strb);
    result = malloc(sizeof(char) * (len + 1));
    if (!result)
        return NULL;
    my_strcpy(result, stra);
    my_strcpy(result + my_strlen(stra), strb);
    result[len] = '\0';
    return result;
}
