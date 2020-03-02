/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** resize_shortcut
*/

#include "my_world.h"

void resize_shortcut(window_t *w, sfEvent *event, int coeff)
{
    if (event->key.shift)
        map_resize_all(w, (sfVector2i){0, coeff});
    else
        map_resize_all(w, (sfVector2i){coeff, 0});
}