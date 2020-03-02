/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** if is clicked
*/

#include "my_world.h"

extern const int EVT_MAP_TRANSLATE_DELTA;
extern const float EVT_MAP_TRANSLATE_PERC;
extern const float EVT_MAP_ROTATE_PERC;

void action_mouse_wheel_clicked(window_t *w)
{
    sfVector2i delta_coord;
    int x = 0;
    int y = 0;

    delta_coord.x = (w->evt.mouse_coord.x - w->evt.mouse_click_coord.x);
    delta_coord.y = (w->evt.mouse_coord.y - w->evt.mouse_click_coord.y);
    if (ABS(delta_coord.x) > 10) {
        x = delta_coord.x * EVT_MAP_TRANSLATE_PERC;
    }
    if (ABS(delta_coord.y) > 10) {
        y = delta_coord.y * EVT_MAP_TRANSLATE_PERC;
    }
    map_translate(&w->map, x, y, w);
    map_translate(&w->map_water, x, y, w);
}

void action_mouse_left_clicked(window_t *w)
{
    sfVector2i delta_coord;
    int x = 0;
    int y = 0;

    delta_coord.x = (w->evt.mouse_coord.x - w->evt.mouse_click_coord.x);
    delta_coord.y = (w->evt.mouse_coord.y - w->evt.mouse_click_coord.y);
    if (ABS(delta_coord.x) > 10) {
        x = delta_coord.x * EVT_MAP_ROTATE_PERC;
    }
    if (ABS(delta_coord.y) > 10) {
        y = delta_coord.y * EVT_MAP_ROTATE_PERC;
    }
    map_rotate(&w->map, x, y);
    map_rotate(&w->map_water, x, y);
}
