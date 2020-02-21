/*
** EPITECH PROJECT, 2019
** CPE_get_next_line_2019
** File description:
** get next line
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "get_next_line.h"
#include <stdio.h>

static int my_strcpylen(char *dest, char const *src, bool c)
{
    int i = 0;

    if (c) {
        if (dest == NULL)
            return 0;
        for (i = 0; src[i] != '\0'; i++)
            dest[i] = src[i];
        dest[i] = '\0';
        return i;
    }
    else {
        for (i = 0; dest[i] != '\0'; i++);
        return i;
    }
}

static char *my_realloc(char *src, size_t bytes)
{
    char *str = malloc(sizeof(char) * bytes);

    if (str == NULL)
        return NULL;
    my_strcpylen(str, src, true);
    free(src);
    return str;
}

static int check_end_line(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            return i;
    return -1;
}

static char *return_str(char *str, char *tampon)
{
    if (check_end_line(str) > -1) {
        my_strcpylen(tampon, str+check_end_line(str)+1, true);
        str[check_end_line(str)] = '\0';
        return str;
    }
    else {
        if (my_strcpylen(str, NULL, false) == 0) {
            free(str);
            return NULL;
        }
        else
            return str;
    }
}

char *get_next_line(int fd)
{
    static char tampon[READ_SIZE] = {0};
    char *str = malloc(READ_SIZE + my_strcpylen(tampon, NULL, 0) + 1);
    int len = my_strcpylen(str, tampon, true);

    tampon[0] = '\0';
    if (fd == -1 || str == NULL)
        return NULL;
    for (int n = 0; n >= 0;) {
        if (check_end_line(str) == -1) {
            n = read(fd, str+len, READ_SIZE);
            len += n;
        }
        str[len] = '\0';
        if (check_end_line(str) > -1 || n < READ_SIZE)
            return return_str(str, tampon);
        str = my_realloc(str, my_strcpylen(str, NULL, false) + READ_SIZE + 1);
    }
    return NULL;
}