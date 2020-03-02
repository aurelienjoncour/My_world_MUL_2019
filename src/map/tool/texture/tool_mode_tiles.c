/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

static void set_point_texture(int y, int x, map_t *map)
{
    map->texture_const[y][x] = map->selected_texture;
}

static int raise_tiles(map_t *map, int i, int j)
{
    set_point_texture(j, i, map);
    set_point_texture(j, (i - 1), map);
    set_point_texture((j - 1), i, map);
    set_point_texture((j - 1), (i - 1), map);
    map->modified = sfTrue;
    return 1;
}

int texture_tiles_mode(map_t *map, sfVector2f *mouse)
{
    for (int j = map->height - 1; j > 0; j--)
        for (int i = map->width - 1; i > 0; i--) {
            if (point_is_on_triangle(map->map_2d[j][i], map->map_2d[j][i - 1],
                map->map_2d[j - 1][i], *mouse))
                    return raise_tiles(map, i, j);
            if (point_is_on_triangle(map->map_2d[j - 1][i - 1],
                    map->map_2d[j][i - 1], map->map_2d[j - 1][i], *mouse))
                    return raise_tiles(map, i, j);
        }
    return 0;
}
