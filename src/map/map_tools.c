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
    map->modified = sfTrue;
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

int map_translate(map_t *map, sfVector2f *new_origin)
{
    map->origin.x += new_origin->x;
    map->origin.y += new_origin->y;
    map->modified = sfTrue;
    return EXIT_SUCCESS;
}