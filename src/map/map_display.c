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
        map->modified = sfFalse;
    }
    for (int i = 0; i < map->height * (map->width - 1); i++)
        sfRenderWindow_drawVertexArray(window, map->vrtx_x[i], NULL);
    for (int i = 0; i < (map->height - 1) * (map->width); i++)
        sfRenderWindow_drawVertexArray(window, map->vrtx_y[i], NULL);
    return EXIT_SUCCESS;
}