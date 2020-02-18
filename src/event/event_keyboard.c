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
    if (event->key.code == sfKeyUp)
        map_translate(&w->map, &(sfVector2f){0, 10});
    if (event->key.code == sfKeyDown)
        map_translate(&w->map, &(sfVector2f){0, -10});
    if (event->key.code == sfKeyLeft)
        map_translate(&w->map, &(sfVector2f){10, 0});
    if (event->key.code == sfKeyRight)
        map_translate(&w->map, &(sfVector2f){-10, 0});
    if (event->key.code == sfKeyR)
        map_reset(&w->map);
}
