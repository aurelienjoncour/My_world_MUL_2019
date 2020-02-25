/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_reset
*/

#include "my_world.h"

int map_reset(map_t *map)
{
    sfVector3f save_sampling = map->sampling;
    sfVector2f save_angle = map->angle;
    sfVector2f save_origin = map->origin;
    char *map_name = my_strdup(map->map_name);

    map_destroy(map);
    if (map_create(map, map->height, map->width)) {
        return EXIT_FAILURE;
    }
    map->modified = true;
    map->sampling = save_sampling;
    map->angle = save_angle;
    map->origin = save_origin;
    map->map_name = map_name;
    return EXIT_SUCCESS;
}
