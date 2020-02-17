/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** Task01
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
