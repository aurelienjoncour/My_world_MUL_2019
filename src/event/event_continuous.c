/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** execute activated events
*/

#include "event.h"


void event_continuous(window_t *w)
{
    if (w->evt.mouse_wheel_is_clicked) {
        event_show_click(w);
        event_mouse_wheel_clicked(w);
    } else if (w->evt.mouse_left_is_clicked) {
        event_show_click(w);
        event_mouse_left_clicked(w);
    }
}
