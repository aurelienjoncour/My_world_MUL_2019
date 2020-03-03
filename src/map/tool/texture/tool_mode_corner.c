/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

int texture_corner_mode(map_t *map, sfVector2f *mouse)
{
    for (int j = map->height - 1; j > 0; j--) {
        for (int i = map->width - 1; i > 0; i--) {
            if (point_is_on_triangle(map->map_2d[j][i], map->map_2d[j][i - 1],
                map->map_2d[j - 1][i], *mouse)) {
                map->texture_const[j - 1][i - 1] = map->selected_texture;
                map->modified = true;
                return 1;
            }
            if (point_is_on_triangle(map->map_2d[j - 1][i - 1],
                    map->map_2d[j][i - 1], map->map_2d[j - 1][i], *mouse)) {
                map->texture_const[j - 1][i - 1] = map->selected_texture;
                map->modified = true;
                return 1;
            }
        }
    }
    return 0;
}
