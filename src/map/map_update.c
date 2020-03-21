/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_update
*/

#include "my_world.h"

int map_update_all(window_t *w, map_t *map)
{
    object_on_map_refresh(&w->player, map);
    if (map_update(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    map->modified = sfFalse;
    if (map_update(&w->map_water) == EXIT_FAILURE)
        return EXIT_FAILURE;
    w->map_water.modified = sfFalse;
    return EXIT_SUCCESS;
}

int map_update(map_t *map)
{
    destroy_2d_map(map->map_2d, map->height);
    if (create_2d_map(map))
        return EXIT_FAILURE;
    if (!map->map_2d)
        return EXIT_FAILURE;
    map_vertex_destroy(map);
    if (map_vertex_create(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    map_vertex_texture_destroy(map);
    if (map_vertex_texture_create(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
