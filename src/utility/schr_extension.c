/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** strschr
*/

#include "my_world.h"

int schr_extension(char *str, const char *ext)
{
    int cursor_str = my_strlen(str) - 1;
    int cursor_ext = my_strlen(ext) - 1;
    int check = 0;

    for (; cursor_ext > -1 && cursor_str > -1; cursor_str--, cursor_ext--)
        if (str[cursor_str] == ext[cursor_ext])
            check++;
        else
            break;
    if (check == my_strlen(ext))
        return 1;
    else
        return 0;
}
