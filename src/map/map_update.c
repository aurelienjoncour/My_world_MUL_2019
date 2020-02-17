/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_update
*/

#include "my_world.h"

int map_update(map_t *map)
{
    destroy_2d_map(map->map_2d, map->height);
    if (create_2d_map(map))
        return EXIT_FAILURE;
    if (!map->map_2d)
        return EXIT_FAILURE;
    map_vertex_destroy(map);
    return map_vertex_create(map);
}