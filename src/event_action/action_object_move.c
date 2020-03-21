/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Created: 2020-03-06T10:04:13+01:00 | Author: simon
*/

#include "my_world.h"

void action_object_move(window_t *w, sfEvent *event)
{
    if (event->key.code == sfKeyI)
        object_on_map_move(&w->player, &w->map, 0, -1);
    if (event->key.code == sfKeyK)
        object_on_map_move(&w->player, &w->map, 0, 1);
    if (event->key.code == sfKeyJ)
        object_on_map_move(&w->player, &w->map, -1, 0);
    if (event->key.code == sfKeyL)
        object_on_map_move(&w->player, &w->map, 1, 0);
}
