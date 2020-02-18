/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

static bool map_is_point_inrange_coord(sfVector2f *map_point, sfVector2f *coord,
float range)
{
    float pow_x = pow((map_point->x - coord->x), 2);
    float pow_y = pow((map_point->y - coord->y), 2);
    float distance = sqrt(pow_x + pow_y);

    if (distance <= range) {
        return true;
    } else {
        return false;
    }
}

static void map_edit_height_edit_point(map_t *map, sfVector2f *coord,
int y, int x)
{
    sfVector2f *map_point = &map->map_2d[y][x];

    if (map_is_point_inrange_coord(map_point, coord, map->sampling.x)) {
        map->map_3d[y][x]++;
        map->modified = sfTrue;
    }
}

int map_edit_height(map_t *map, sfVector2f *coord)
{
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            map_edit_height_edit_point(map, coord, y, x);
        }
    }
    return EXIT_SUCCESS;
}
