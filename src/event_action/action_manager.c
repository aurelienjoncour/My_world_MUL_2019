/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** execute activated events
*/

#include "event_action.h"

void action_manager(window_t *w)
{
    if (w->evt.mouse_wheel_is_clicked) {
        action_show_click(w);
        action_mouse_wheel_clicked(w);
    } else if (w->evt.mouse_left_is_clicked) {
        action_show_click(w);
        action_mouse_left_clicked(w);
    }
}
