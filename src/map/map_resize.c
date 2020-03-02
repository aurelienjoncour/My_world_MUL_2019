/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_resize
*/

#include "my_world.h"

static void map_add_tiles(map_t *map, map_t *new_map)
{
    for (int i = 0; i < map->height; i++)
        for (int j = 0; j < map->width; j++) {
            new_map->map_3d[i][j] = map->map_3d[i][j];
            new_map->texture_const[i][j] = map->texture_const[i][j];
        }
}

static void map_remove_tiles(map_t *map, map_t *new_map, sfVector2i resize)
{
    for (int i = 0; i < map->height + resize.y; i++)
        for (int j = 0; j < map->width + resize.x; j++) {
            new_map->map_3d[i][j] = map->map_3d[i][j];
            new_map->texture_const[i][j] = map->texture_const[i][j];
        }
}

int map_resize(map_t *map, sfVector2i resize)
{
    map_t new_map;
    char *map_name = my_strdup(map->map_name);

    if (map->height + resize.y < 2 || map->width + resize.x < 2)
        return EXIT_ERROR;
    if (map_create(&new_map, map->height + resize.y, map->width + resize.x))
        return EXIT_FAILURE;
    if (resize.x < 0 || resize.y < 0)
        map_remove_tiles(map, &new_map, resize);
    else
        map_add_tiles(map, &new_map);
    new_map.sampling = map->sampling;
    new_map.angle = map->angle;
    new_map.origin = map->origin;
    new_map.map_name = map_name;
    map_destroy(map);
    new_map.modified = true;
    *map = new_map;
    return EXIT_SUCCESS;
}

int map_resize_all(window_t *w, sfVector2i resize)
{
    if (map_resize(&w->map, resize) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (map_resize(&w->map_water, resize) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}