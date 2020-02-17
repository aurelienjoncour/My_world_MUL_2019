/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_tools
*/

#include "my_world.h"

int map_rotate(map_t *map, sfVector2f *angle)
{
    map->angle = *angle;
    return EXIT_SUCCESS;
}

int map_scale(map_t *map, float scale)
{
    map->sampling.x += scale;
    map->sampling.y += scale;
    if (map->sampling.y >= 0 && scale > 0)
        map->sampling.z += scale;
    return EXIT_SUCCESS;
}

int map_translate(map_t *map, sfVector2f *new_origin)
{
    map->origin = *new_origin;
    return EXIT_SUCCESS;
}