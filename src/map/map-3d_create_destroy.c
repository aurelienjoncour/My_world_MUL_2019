/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create_3d_map
*/

#include "my_world.h"

static void init_3d_map(int **map_3d, int height, int width)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            map_3d[i][j] = 0;
    }
}

int **create_3d_map(int height, int width)
{
    int **map_3d = malloc(sizeof(int *) * height);

    if (!map_3d) {
        my_putstr_error("create_3d_map: malloc error\n");
        return NULL;
    }
    for (int i = 0; i < height; i++) {
        map_3d[i] = malloc(sizeof(int) * width);
        if (!map_3d[i]) {
            my_putstr_error("create_3d_map: malloc error\n");
            return NULL;
        }
    }
    init_3d_map(map_3d, height, width);
    return map_3d;
}

void destroy_3d_map(int **map_3d, int height)
{
    for (int i = 0; i < height; i++)
        free(map_3d[i]);
    free(map_3d);
}
