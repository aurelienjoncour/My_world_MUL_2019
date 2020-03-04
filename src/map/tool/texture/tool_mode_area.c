/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** tool_range
*/

#include "my_world.h"

static bool map_is_point_inrange_coord(sfVector2f *map_point,
sfVector2f *coord, slider_t *slider, float sampling)
{
    float coef = (slider_get_value(slider) + 0.1);
    float range = (sampling * (coef * 10));
    float pow_x = pow((map_point->x - coord->x), 2);
    float pow_y = pow((map_point->y - coord->y), 2);
    float distance = sqrt(pow_x + pow_y);

    if (distance <= range)
        return true;
    else
        return false;
}

static int map_edit_area(map_t *map, sfVector2f *coord,
sfVector2i indice, slider_t *slider)
{
    sfVector2f *map_point = &map->map_2d[indice.y][indice.x];
    float sampling = map->sampling.x;

    if (map_is_point_inrange_coord(map_point, coord, slider, sampling)) {
        map->texture_const[indice.y][indice.x] = map->selected_texture;
        map->modified = sfTrue;
        return 1;
    }
    return 0;
}

int texture_area_mode(map_t *map, sfVector2f *mouse, slider_t *slider)
{
    int exit_status = 0;
    int ret = 0;
    sfVector2i indice = {0};

    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            indice.x = x;
            indice.y = y;
            ret = map_edit_area(map, mouse, indice, slider);
            exit_status = (ret == 1) ? (1) : exit_status;
        }
    }
    return exit_status;
}
