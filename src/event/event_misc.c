/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "event_action.h"

void event_window_close(window_t *w)
{
    sfRenderWindow_close(w->window);
}

void event_resize_window(window_t *w, sfEvent *event)
{
    w->width = (int)event->size.width;
    w->height = (int)event->size.height;
}
