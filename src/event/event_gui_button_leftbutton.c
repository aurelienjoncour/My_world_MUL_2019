/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_world.h"

void check_event_button_toolbar(window_t *w, enum button_status status,
int x, int y)
{
    if (button_poll_event(&w->ui.raise, x, y, status, ACTIVE)) {

    }
    if (button_poll_event(&w->ui.lower, x, y, status, ACTIVE)) {

    }
    if (button_poll_event(&w->ui.level, x, y, status, ACTIVE)) {

    }
    if (button_poll_event(&w->ui.texture, x, y, status, ACTIVE)) {

    }
    if (button_poll_event(&w->ui.select_mode, x, y, status, ACTIVE)) {
        update_select_mode(w);
    }
}

void check_event_button_leftbar(window_t *w, enum button_status status,
int x, int y)
{
    if (button_poll_event(&w->ui.map_y_p, x, y, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){0, 1});
    }
    if (button_poll_event(&w->ui.map_y_m, x, y, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){0, -1});
    }
    if (button_poll_event(&w->ui.map_x_m, x, y, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){-1, 0});
    }
    if (button_poll_event(&w->ui.map_x_p, x, y, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){1, 0});
    }
    if (button_poll_event(&w->ui.menu_texture, x, y, status, ACTIVE)) {

    }
}
