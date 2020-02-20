/*
** EPITECH PROJECT, 2019
** my_str_word_array
** File description:
** split a string into words
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

static bool is_itdelim(char c, char *delim)
{
    for (int i = 0; delim[i] != '\0'; i++)
        if (delim[i] == c)
            return true;
    return false;
}

static char **my_str_to_word_array_rec(char *str, char *delim, int j)
{
    char **word_array = NULL;
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (is_itdelim(str[i], delim) && !is_itdelim(str[i+1], delim)
            && str[i+1] != '\0') {
            word_array = my_str_to_word_array_rec(str+i+1, delim, j + 1);
            break;
        }
    if (word_array == NULL) {
        word_array = malloc(sizeof(char *) * (j + 2));
        if (word_array == NULL)
            return NULL;
        word_array[j+1] = NULL;
    }
    for (y = 0; str[y] != '\0'; y++)
        if (is_itdelim(str[y], delim))
            break;
    word_array[j] = my_strndup(str, y);
    return word_array;
}

char **my_str_to_word_array(char *str, char *delim)
{
    char **word_array;
    size_t i;

    for (i = 0; is_itdelim(str[i], delim); i++);
    word_array = my_str_to_word_array_rec(str+i, delim, 0);
    return word_array;
}
