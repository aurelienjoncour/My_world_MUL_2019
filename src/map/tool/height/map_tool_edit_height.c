/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

int get_dynamical_coefficient(int point_height)
{
    if (point_height > 0)
        return -1;
    else if (point_height < 0)
        return 1;
    else
        return 0;
}

static int map_edit_call_mode(window_t *w, sfVector2f *mouse, int coefficient)
{
    if (w->state.select_mode == TILE)
        return tiles_mode(&w->map, mouse, coefficient);
    if (w->state.select_mode == CORNER)
        return corner_mode(&w->map, mouse, coefficient);
    if (w->state.select_mode == AREA)
        return area_mode(&w->map, mouse, coefficient);
    return 0;
}

int map_edit_height(window_t *w, float x, float y)
{
    sfVector2f mouse = {x, y};
    int coefficient;

    if (w->state.tool == RAISE)
        coefficient = 1;
    else if (w->state.tool == LOWER)
        coefficient = -1;
    else
        coefficient = 0;
    return map_edit_call_mode(w, &mouse, coefficient);
}
