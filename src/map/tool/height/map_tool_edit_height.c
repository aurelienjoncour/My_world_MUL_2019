/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

int get_dynamical_coefficient(int point_height)
{
    int coef = 0;

    coef = (-point_height) / 2;
    if (coef && abs(coef) <= 4)
        coef = -point_height;
    return coef;
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
    coefficient *= ((slider_get_value(&w->ui.slider) * 10) + 1);
    return map_edit_call_mode(w, &mouse, coefficient);
}
