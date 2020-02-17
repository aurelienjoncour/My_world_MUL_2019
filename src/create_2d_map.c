/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create_2d_map
*/

#include "my_world.h"

sfVector2f **create_2d_map(int **map_3d, int width, int height)
{
    sfVector2f **map = malloc(sizeof(sfVector2f *) * height);

    if (!map) {
        my_putstr_error("create_2d_map: malloc error\n");
        return NULL;
    }
    for (size_t i = 0; i < height; i++) {
        map[i] = malloc(sizeof(sfVector2f) * width);
        if (!map[i]) {
            my_putstr_error("create_2d_map: malloc error\n");
            return NULL;
        }
    }
    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width; x++) {
            map[y][x] = project_iso_point(x, y, map_3d[y][x], (sfVector2f){0, 450});
        }
    }
    return map;
}

void destroy_2d_map(sfVector2f **map_2d, int height)
{
    for (int i = 0; i < height; i++)
        free(map_2d[i]);
    free(map_2d);
}