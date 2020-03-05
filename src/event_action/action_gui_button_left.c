/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Action GUI Buttons on the left
*/

#include "my_world.h"

extern const int WIN_WIDTH;
extern const sfVector3f MAP_INIT_SAMP;
extern const sfVector2f MAP_INIT_ANGL;
extern const sfVector2f MAP_INIT_ORIG;

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
        w->map.sampling = MAP_INIT_SAMP;
        w->map_water.sampling = MAP_INIT_SAMP;
        w->map.modified = sfTrue;
        return 1;
    }
    if (button_poll_event(&w->ui.translate, mouse, status, ACTIVE)) {
        w->map.origin = MAP_INIT_ORIG;
        w->map_water.origin = MAP_INIT_ORIG;
        w->map.modified = sfTrue;
        return 1;
    }
    if (button_poll_event(&w->ui.rotate, mouse, status, ACTIVE)) {
        w->map.angle = MAP_INIT_ANGL;
        w->map_water.angle = MAP_INIT_ANGL;
        w->map.modified = sfTrue;
        return 1;
    }
    return 0;
}
