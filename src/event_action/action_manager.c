/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** execute activated events
*/

#include "event_action.h"
#include "texture_menu.h"

void action_manager(window_t *w)
{
    if (w->evt.mouse_wheel_is_clicked) {
        action_show_click(w);
        action_mouse_wheel_clicked(w);
    } else if (w->evt.mouse_left_is_clicked) {
        action_show_click(w);
        action_mouse_left_clicked(w);
    }
    if (w->state.help_menu)
        image_viewer_display(&w->ui.help_menu_viewer, &w->state.help_menu);
    if (w->state.texture_menu)
        texture_menu_display(&w->ui.txr_menu, &w->map, &w->state.texture_menu);
    if (w->reload_window && !w->evt.mouse_left_is_clicked &&
    w->evt.cursor_in_window) {
        event_window_close(w);
    }
}
