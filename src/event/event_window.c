/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Action => window
*/

#include "event_action.h"

void event_window_close(window_t *w)
{
    sfRenderWindow_close(w->window);
}

void event_resize_window(window_t *w, sfEvent *event)
{
    static sfBool apply = sfTrue;

    if (!apply) {
        apply = sfTrue;
        w->width = (int)event->size.width;
        w->height = (int)event->size.height;
        w->reload_window = sfTrue;
    } else {
        apply = sfFalse;
    }
}
