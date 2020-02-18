/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "event.h"

void event_manager(window_t *w, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        event_window_close(w);
    if (event->type == sfEvtMouseButtonPressed)
        event_mouse_click(w, event);
    else if (event->type == sfEvtMouseWheelScrolled)
        event_mouse_wheel_scroll(w, event);
    if (event->type == sfEvtKeyPressed)
        event_keypressed(w, event);
    if (event->type == sfEvtResized)
        event_resize_window(w, event);
}
