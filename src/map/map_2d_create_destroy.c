/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create_2d_map
*/

#include "my_world.h"

int create_2d_map(map_t *map)
{
    int map_point;

    map->map_2d = malloc(sizeof(sfVector2f *) * map->height);
    if (!map->map_2d) {
        my_putstr_error("create_2d_map: malloc error\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < map->height; i++) {
        map->map_2d[i] = malloc(sizeof(sfVector2f) * map->width);
        if (!map->map_2d[i]) {
            my_putstr_error("create_2d_map: malloc error\n");
            return EXIT_FAILURE;
        }
    }
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            map_point = map->map_3d[y][x];
            map->map_2d[y][x] = project_iso_point(x, y, map_point, map);
        }
    }
    return EXIT_SUCCESS;
}

void destroy_2d_map(sfVector2f **map_2d, int height)
{
    for (int i = 0; i < height; i++)
        free(map_2d[i]);
    free(map_2d);
}
