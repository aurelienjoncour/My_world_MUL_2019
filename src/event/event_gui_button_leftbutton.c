/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_world.h"

static int check_event_button_toolbar_sub(window_t *w,
enum button_status status, int x, int y)
{
    sfVector2i mouse = {.x = x, .y = y};
    if (button_poll_event(&w->ui.level, mouse, status, ACTIVE)) {
        action_gui_button_tool(&w->ui.level, &w->state, &w->ui, LEVEL);
        return 1;
    }
    if (button_poll_event(&w->ui.texture, mouse, status, ACTIVE)) {
        action_gui_button_tool(&w->ui.texture, &w->state, &w->ui, TEXTURE);
        return 1;
    }
    return 0;
}

int check_event_button_toolbar(window_t *w, enum button_status status,
sfVector2i mouse)
{
    if (button_poll_event(&w->ui.raise, mouse, status, ACTIVE)) {
        action_gui_button_tool(&w->ui.raise, &w->state, &w->ui, RAISE);
        return 1;
    }
    if (button_poll_event(&w->ui.lower, mouse, status, ACTIVE)) {
        action_gui_button_tool(&w->ui.lower, &w->state, &w->ui, LOWER);
        return 1;
    }
    if (check_event_button_toolbar_sub(w, status, mouse.x, mouse.y) != 0)
        return 1;
    return 0;
}

static int check_event_button_leftbar_sub(window_t *w,
enum button_status status, sfVector2i mouse)
{
    if (button_poll_event(&w->ui.select_mode, mouse, status, ACTIVE)) {
        update_select_mode(w);
        return 1;
    }
    if (button_poll_event(&w->ui.menu_texture, mouse, status, ACTIVE)) {

        return 1;
    }
    return 0;
}

int check_event_button_leftbar(window_t *w, enum button_status status,
sfVector2i mouse)
{
    if (button_poll_event(&w->ui.map_y_p, mouse, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){0, 1});
        return 1;
    }
    if (button_poll_event(&w->ui.map_y_m, mouse, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){0, -1});
        return 1;
    }
    if (button_poll_event(&w->ui.map_x_m, mouse, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){-1, 0});
        return 1;
    }
    if (button_poll_event(&w->ui.map_x_p, mouse, status, ACTIVE)) {
        map_resize(&w->map, (sfVector2i){1, 0});
        return 1;
    }
    if (check_event_button_leftbar_sub(w, status, mouse) != 0)
        return 1;
    return 0;
}
