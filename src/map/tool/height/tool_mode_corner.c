/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

static sfVector2i search_point(map_t *map, sfVector2f *mouse)
{
    float distance = point_length(*mouse, map->map_2d[0][0]);
    sfVector2i save;

    for (int i = map->height - 1; i >= 0; i--) {
        for (int j = map->width - 1; j >= 0; j--) {
            if (point_length(*mouse, map->map_2d[i][j]) < distance) {
                distance = point_length(*mouse, map->map_2d[i][j]);
                save.x = j;
                save.y = i;
            }
        }
    }
    return save;
}

int corner_mode(map_t *map, sfVector2f *mouse, int coefficient)
{
    static sfVector2i save = {0};
    static sfVector2f prev_mouse = {0};
    float distance_last_click = point_length(*mouse, prev_mouse);

    prev_mouse = *mouse;
    if (distance_last_click < map->sampling.x) {
        map->map_3d[save.y][save.x] += coefficient;
        map->modified = true;
        return EXIT_SUCCESS;
    }
    save = search_point(map, mouse);
    if (coefficient == 0)
        coefficient = get_dynamical_coefficient(map->map_3d[save.y][save.x]);
    map->map_3d[save.y][save.x] += coefficient;
    map->modified = true;
    return 1;
}
