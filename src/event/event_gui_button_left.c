/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_world.h"

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

static int check_event_button_leftbar_down(window_t *w,
enum button_status status, sfVector2i mouse)
{
    if (button_poll_event(&w->ui.select_mode, mouse, status, ACTIVE)) {
        update_select_mode(w);
        return 1;
    }
    if (button_poll_event(&w->ui.menu_texture, mouse, status, ACTIVE)) {
        texture_menu_status(&w->ui.txr_menu, &w->state.texture_menu);
        return 1;
    }
    return 0;
}

int check_event_button_leftbar(window_t *w, enum button_status status,
sfVector2i mouse)
{
    if (button_poll_event(&w->ui.map_y_p, mouse, status, ACTIVE)) {
        map_resize_all(w, (sfVector2i){0, 1});
        return 1;
    }
    if (button_poll_event(&w->ui.map_y_m, mouse, status, ACTIVE)) {
        map_resize_all(w, (sfVector2i){0, -1});
        return 1;
    }
    if (button_poll_event(&w->ui.map_x_m, mouse, status, ACTIVE)) {
        map_resize_all(w, (sfVector2i){-1, 0});
        return 1;
    }
    if (button_poll_event(&w->ui.map_x_p, mouse, status, ACTIVE)) {
        map_resize_all(w, (sfVector2i){1, 0});
        return 1;
    }
    if (check_event_button_leftbar_down(w, status, mouse) != 0)
        return 1;
    return 0;
}

int check_event_button_view(window_t *w, enum button_status status,
sfVector2i mouse)
{
    if (button_poll_event(&w->ui.scale, mouse, status, ACTIVE)) {

        return 1;
    }
    if (button_poll_event(&w->ui.translate, mouse, status, ACTIVE)) {

        return 1;
    }
    if (button_poll_event(&w->ui.rotate, mouse, status, ACTIVE)) {

        return 1;
    }
    return 0;
}
