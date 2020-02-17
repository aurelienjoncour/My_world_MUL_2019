/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_t
*/

#include "my_world.h"

void destroy_map(map_t *map)
{
    destroy_2d_map(map->map_2d, map->height);
    destroy_3d_map(map->map_3d, map->height);
}

int create_map(map_t *map, int height, int width)
{
    map->map_3d = create_3d_map(height, width);
    if (!map->map_3d)
        return EXIT_FAILURE;
    map->map_2d = create_2d_map(map->map_3d, width, height);
    if (!map->map_2d)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}