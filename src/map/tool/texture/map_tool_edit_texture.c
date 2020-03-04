/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

static int map_edit_call_mode(window_t *w, sfVector2f *mouse)
{
    if (w->state.select_mode == TILE)
        return texture_tiles_mode(&w->map, mouse);
    if (w->state.select_mode == CORNER)
        return texture_corner_mode(&w->map, mouse);
    if (w->state.select_mode == AREA)
        return texture_area_mode(&w->map, mouse, &w->ui.slider);
    return 0;
}

int map_edit_texture(window_t *w, float x, float y)
{
    sfVector2f mouse = {x, y};

    return map_edit_call_mode(w, &mouse);
}
