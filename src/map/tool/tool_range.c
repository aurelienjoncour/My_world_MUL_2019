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

int map_edit_height_edit_point(map_t *map, sfVector2f *coord,
sfVector2i indice, int coefficient)
{
    sfVector2f *map_point = &map->map_2d[indice.y][indice.x];
    int ret = 0;

    if (map_is_point_inrange_coord(map_point, coord, map->sampling.x)) {
        map->map_3d[indice.y][indice.x] += coefficient;
        map->modified = sfTrue;
        ret = 1;
    }
    return ret;
}