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

int map_scale(map_t *map, sfVector3f *scale)
{
    map->sampling = *scale;
    return EXIT_SUCCESS;
}

int map_translate(map_t *map, sfVector2f *new_origin)
{
    map->origin = *new_origin;
    return EXIT_SUCCESS;
}