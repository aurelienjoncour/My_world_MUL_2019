/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event
*/

#ifndef EVENT_H_
#define EVENT_H_

#include "my_world.h"

void event_init(event_t *evt);
void event_manager(window_t *w, sfEvent *event);

void event_window_close(window_t *w);
void event_resize_window(window_t *w, sfEvent *event);

void event_mouse_button_pressed(window_t *w, sfEvent *event);
void event_mouse_button_released(window_t *w, sfEvent *event);
void event_mouse_wheel_scroll(window_t *w, sfEvent *event);
void event_mouse_wheel_click(window_t *w, sfEvent *event);
void event_mouse_move(window_t *w, sfEvent *event);
void event_mouse_in_out_window(window_t *w, sfEvent *event);
void event_mouse_guibutton(window_t *w, sfEvent *event);
void check_event_button_toolbar(window_t *w, enum button_status status,
int x, int y);
void check_event_button_leftbar(window_t *w, enum button_status status,
int x, int y);

void event_keypressed(window_t *w, sfEvent *event);
void event_window_close(window_t *w);

void action_manager(window_t *w);
void action_show_click(window_t *w);
void action_mouse_wheel_clicked(window_t *w);
void action_mouse_left_clicked(window_t *w);

void action_map_save(window_t *w);
void action_map_load(window_t *w);
void update_mape_name(window_t *w, char *new_name);
void update_select_mode(window_t *w);

#endif
