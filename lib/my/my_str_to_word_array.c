/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** Task04
*/

#include <stdlib.h>

static int is_alphanum(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90))
        return (1);
    if (c >= 97 && c <= 122)
        return (1);
    return (0);
}

static void count_word_let(char const *str, int *cword, int *calphanum)
{
    int can_word = 0;
    int i = -1;

    while (str[++i] != '\0') {
        if (is_alphanum(str[i]) == 1) {
            can_word++;
        } else if (can_word > *calphanum) {
            *calphanum = can_word;
        }
        if (is_alphanum(str[i]) != 1 && can_word != 0 && str[i + 1] != '\0') {
            can_word = 0;
            (*cword)++;
        }
    }
    *calphanum += can_word;
    (*cword)++;
}

static void fill_array(int cword, char const *str, char **ret)
{
    int i_word = 0;
    int j = 0;

    for (int i = 0; i < cword; i++) {
        while (is_alphanum(str[j]) == 1) {
            ret[i][i_word] = str[j];
            j++;
            i_word++;
        }
        if (i_word == 0) {
            j++;
            i--;
        } else {
            i_word = 0;
        }
    }
    ret[cword] = 0;
}

char **my_str_to_word_array(char const *str)
{
    int cword = 0;
    int calphanum = 0;
    char **ret;

    count_word_let(str, &cword, &calphanum);
    ret = malloc(sizeof(char *) * (1 + cword));
    if (calphanum == 0) {
        ret[0] = NULL;
        return (ret);
    }
    for (int i = 0; i < (cword + 1); i++)
        ret[i] = malloc(sizeof(char) * calphanum);
    if (ret == NULL)
        return (ret);
    fill_array(cword, str, ret);
    return (ret);
}
