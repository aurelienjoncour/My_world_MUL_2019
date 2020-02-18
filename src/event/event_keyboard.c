/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_world.h"
#include "event.h"

extern const int EVT_MAP_TRANSLATE_DELTA;
extern const sfKeyCode KEY_MAP_TRANS_UP;
extern const sfKeyCode KEY_MAP_TRANS_DOWN;
extern const sfKeyCode KEY_MAP_TRANS_LEFT;
extern const sfKeyCode KEY_MAP_TRANS_RIGHT;

extern const sfKeyCode KEY_MAP_ROT_UP;
extern const sfKeyCode KEY_MAP_ROT_DOWN;
extern const sfKeyCode KEY_MAP_ROT_LEFT;
extern const sfKeyCode KEY_MAP_ROT_RIGHT;

void event_key_zqsd(window_t *w, sfEvent *event)
{
    if (event->key.code == KEY_MAP_TRANS_UP)
        map_translate(&w->map, 0, EVT_MAP_TRANSLATE_DELTA);
    if (event->key.code == KEY_MAP_TRANS_DOWN)
        map_translate(&w->map, 0, -EVT_MAP_TRANSLATE_DELTA);
    if (event->key.code == KEY_MAP_TRANS_LEFT)
        map_translate(&w->map, EVT_MAP_TRANSLATE_DELTA, 0);
    if (event->key.code == KEY_MAP_TRANS_RIGHT)
        map_translate(&w->map, -EVT_MAP_TRANSLATE_DELTA, 0);
}

void event_key_arrow(window_t *w, sfEvent *event)
{
    if (event->key.code == KEY_MAP_ROT_UP)
        map_rotate(&w->map, 0, 10);
    if (event->key.code == KEY_MAP_ROT_DOWN)
        map_rotate(&w->map, 0, -10);
    if (event->key.code == KEY_MAP_ROT_LEFT)
        map_rotate(&w->map, 10, 0);
    if (event->key.code == KEY_MAP_ROT_RIGHT)
        map_rotate(&w->map, -10, 0);
}

void event_keypressed(window_t *w, sfEvent *event)
{
    if (event->key.code == sfKeyEscape)
        event_window_close(w);
    if (event->key.code == sfKeyR)
        map_reset(&w->map);
    if (event->key.code == KEY_MAP_TRANS_UP ||
    event->key.code == KEY_MAP_TRANS_DOWN ||
    event->key.code == KEY_MAP_TRANS_LEFT ||
    event->key.code == KEY_MAP_TRANS_RIGHT) {
        event_key_zqsd(w, event);
    }
    if (event->key.code == KEY_MAP_ROT_UP ||
    event->key.code == KEY_MAP_ROT_DOWN ||
    event->key.code == KEY_MAP_ROT_LEFT ||
    event->key.code == KEY_MAP_ROT_RIGHT) {
        event_key_arrow(w, event);
    }
}
