/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_world.h"

int check_event_button_toolbar(window_t *w, enum button_status status,
int x, int y)
{
    if (button_poll_event(&w->ui.raise, x, y, status, ACTIVE)) {
        return action_gui_button_tool(&w->ui.raise, &w->state, &w->ui, RAISE);
    }
    if (button_poll_event(&w->ui.lower, x, y, status, ACTIVE)) {
        return action_gui_button_tool(&w->ui.lower, &w->state, &w->ui, LOWER);
    }
    if (button_poll_event(&w->ui.level, x, y, status, ACTIVE)) {
        return action_gui_button_tool(&w->ui.level, &w->state, &w->ui, LEVEL);
    }
    if (button_poll_event(&w->ui.texture, x, y, status, ACTIVE)) {
        return action_gui_button_tool(&w->ui.texture, &w->state, &w->ui,
                                     TEXTURE);
    }
    if (button_poll_event(&w->ui.select_mode, x, y, status, ACTIVE)) {
        update_select_mode(w);
        return 1;
    }
    return 0;
}

int check_event_button_leftbar(window_t *w, enum button_status status,
int x, int y)
{
    if (button_poll_event(&w->ui.map_y_p, x, y, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){0, 1});
        return 1;
    }
    if (button_poll_event(&w->ui.map_y_m, x, y, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){0, -1});
        return 1;
    }
    if (button_poll_event(&w->ui.map_x_m, x, y, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){-1, 0});
        return 1;
    }
    if (button_poll_event(&w->ui.map_x_p, x, y, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){1, 0});
        return 1;
    }
    if (button_poll_event(&w->ui.menu_texture, x, y, status, ACTIVE)) {

        return 1;
    }
    return 0;
}
