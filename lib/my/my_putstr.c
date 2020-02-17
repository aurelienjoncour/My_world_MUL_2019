/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Task02
*/

#include "my.h"

int my_putchar(char c);

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return len;
}
