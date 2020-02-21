/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

// static bool map_is_point_inrange_coord(sfVector2f *map_point, sfVector2f *coord,
// float range)
// {
//     float pow_x = pow((map_point->x - coord->x), 2);
//     float pow_y = pow((map_point->y - coord->y), 2);
//     float distance = sqrt(pow_x + pow_y);

//     if (distance <= range) {
//         return true;
//     } else {
//         return false;
//     }
// }

// static int map_edit_height_edit_point(map_t *map, sfVector2f *coord,
// int y, int x)
// {
//     sfVector2f *map_point = &map->map_2d[y][x];
//     int ret = 0;

//     if (map_is_point_inrange_coord(map_point, coord, map->sampling.x)) {
//         map->map_3d[y][x]++;
//         map->modified = sfTrue;
//         ret = 1;
//     }
//     return ret;
// }

// int map_edit_height(map_t *map, float x, float y)
// {
//     sfVector2f coord = {x, y};
//     int exit_status = 0;
//     int ret = 0;

//     for (int y = 0; y < map->height; y++) {
//         for (int x = 0; x < map->width; x++) {
//             ret = map_edit_height_edit_point(map, &coord, y, x);
//             exit_status = (ret == 1) ? (1) : exit_status;
//         }
//     }
//     return exit_status;
// }

static int raise_tiles(map_t *map, int i, int j)
{
    map->map_3d[j][i]++;
    map->map_3d[j][i - 1]++;
    map->map_3d[j - 1][i]++;
    map->map_3d[j - 1][i - 1]++;
    map->modified = sfTrue;
    return 1;
}


int map_edit_height(map_t *map, float x, float y)
{
    sfVector2f m = {x, y};

    for (int j = map->height - 1; j > 0; j--)
        for (int i = map->width - 1; i > 0; i--) {
            if (point_is_on_triangle(map->map_2d[j][i], map->map_2d[j][i - 1],
                                    map->map_2d[j - 1][i], m))
                return raise_tiles(map, i, j);
            if (point_is_on_triangle(map->map_2d[j - 1][i - 1],
                map->map_2d[j][i - 1], map->map_2d[j - 1][i], m))
                return raise_tiles(map, i, j);
        }
    return 0;
}
