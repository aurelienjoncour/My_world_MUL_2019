/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event
*/

#ifndef EVENT_H_
#define EVENT_H_

#include "my_world.h"

void event_manager(window_t *w, sfEvent *event);

void event_window_close(window_t *w);
void event_resize_window(window_t *w, sfEvent *event);

void event_mouse_click(window_t *w, sfEvent *event);
void event_mouse_wheel_scroll(window_t *w, sfEvent *event);

void event_keypressed(window_t *w, sfEvent *event);

void event_window_close(window_t *w);

#endif
