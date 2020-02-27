/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

int texture_corner_mode(map_t *map, sfVector2f *mouse)
{
    float distance = point_length(*mouse, map->map_2d[0][0]);
    sfVector2i save = {0};

    for (int i = map->height - 1; i >= 0; i--) {
        for (int j = map->width - 1; j >= 0; j--) {
            if (point_length(*mouse, map->map_2d[i][j]) < distance) {
                distance = point_length(*mouse, map->map_2d[i][j]);
                save.x = j;
                save.y = i;
            }
        }
    }
    map->texture_lay[save.y][save.x] = map->textures[map->selected_texture];
    map->modified = true;
    return 1;
}
