/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_scale
*/

#include "my_world.h"

int map_scale_all(window_t *w, float scale)
{
    map_scale(&w->map, scale);
    map_scale(&w->map_water, scale);
    return EXIT_SUCCESS;
}

int map_scale(map_t *map, float scale)
{
    if ((map->sampling.x != 0) || (map->sampling.x == 0 && scale > 0))
        map->sampling.x += scale;
    if ((map->sampling.y != 0) || (map->sampling.y == 0 && scale > 0))
        map->sampling.y += scale;
    if ((map->sampling.z != 0) || (map->sampling.z == 0 && scale > 0))
        map->sampling.z += scale * 10 / 64;
    map->modified = sfTrue;
    return EXIT_SUCCESS;
}