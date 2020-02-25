/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

static void set_point_height(int *point, int coefficient)
{
    if (coefficient == 0) {
        coefficient = get_dynamical_coefficient(*point);
    }
    *point += coefficient;
}

static int raise_tiles(map_t *map, int i, int j, int coefficient)
{
    set_point_height(&map->map_3d[j][i], coefficient);
    set_point_height(&map->map_3d[j][i - 1], coefficient);
    set_point_height(&map->map_3d[j - 1][i], coefficient);
    set_point_height(&map->map_3d[j - 1][i - 1], coefficient);
    map->modified = sfTrue;
    return 1;
}

int tiles_mode(map_t *map, sfVector2f *mouse, int coefficient)
{
    for (int j = map->height - 1; j > 0; j--)
        for (int i = map->width - 1; i > 0; i--) {
            if (point_is_on_triangle(map->map_2d[j][i], map->map_2d[j][i - 1],
                       map->map_2d[j - 1][i], *mouse))
                    return raise_tiles(map, i, j, coefficient);
            if (point_is_on_triangle(map->map_2d[j - 1][i - 1],
                    map->map_2d[j][i - 1], map->map_2d[j - 1][i], *mouse))
                    return raise_tiles(map, i, j, coefficient);
        }
    return 0;
}
