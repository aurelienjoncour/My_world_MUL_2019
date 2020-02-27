/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** tool_range
*/

#include "my_world.h"

static bool map_is_point_inrange_coord(sfVector2f *map_point, sfVector2f *coord,
float range)
{
    float pow_x = pow((map_point->x - coord->x), 2);
    float pow_y = pow((map_point->y - coord->y), 2);
    float distance = sqrt(pow_x + pow_y);

    if (distance <= range)
        return true;
    else
        return false;
}

static int map_edit_height_edit_point(map_t *map, sfVector2f *coord,
sfVector2i indice, int coefficient)
{
    sfVector2f *map_point = &map->map_2d[indice.y][indice.x];
    int ret = 0;
    int dyn_coefficient = coefficient;
    int point_height;

    if (map_is_point_inrange_coord(map_point, coord, map->sampling.x)) {
        if (coefficient == 0) {
            point_height = map->map_3d[indice.y][indice.x];
            dyn_coefficient = get_dynamical_coefficient(point_height);
        }
        map->map_3d[indice.y][indice.x] += dyn_coefficient;
        map->modified = sfTrue;
        ret = 1;
    }
    return ret;
}

int area_mode(map_t *map, sfVector2f *mouse, int coefficient)
{
    int exit_status = 0;
    int ret = 0;
    sfVector2i indice = {0};

    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            indice.x = x;
            indice.y = y;
            ret = map_edit_height_edit_point(map, mouse, indice, coefficient);
            exit_status = (ret == 1) ? (1) : exit_status;
        }
    }
    return exit_status;
}
