/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_world.h"


void event_mouse_click(window_t *w, sfEvent *event)
{
    sfMouseButtonEvent evt = event->mouseButton;

    //evt.x += evt.y + w->exit_status;
}

void event_mouse_wheel_scroll(window_t *w, sfEvent *event)
{
    sfMouseWheelScrollEvent evt = event->mouseWheelScroll;

    map_scale(&w->map, evt.delta);
}
