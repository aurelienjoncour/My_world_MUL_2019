/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_world.h"
#include "event.h"

void event_keypressed(window_t *w, sfEvent *event)
{
    if (event->key.code == sfKeyEscape)
        event_window_close(w);
}
