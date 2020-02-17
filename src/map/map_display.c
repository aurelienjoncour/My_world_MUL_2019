/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_2d_map
*/

#include "my_world.h"

int map_display(sfRenderWindow *window, map_t *map)
{
    if (map->modified) {
        map_update(map);
    }
    for (int i = 0; i < (map->width * map->height); i++) {
        sfRenderWindow_drawVertexArray(window, map->vrtx_y[i], NULL);
        sfRenderWindow_drawVertexArray(window, map->vrtx_x[i], NULL);
    }
}
