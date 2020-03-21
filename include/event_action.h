/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event
*/

#ifndef EVENT_H_
#define EVENT_H_

#include "my_world.h"

// EVENT

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
int action_mouse_guibutton(window_t *w, sfEvent *event);
int check_event_button_toolbar(window_t *w, enum button_status status,
sfVector2i mouse);
int check_event_button_view(window_t *w, enum button_status status,
sfVector2i mouse);
int check_event_button_leftbar(window_t *w, enum button_status status,
sfVector2i mouse);
int check_event_button_topbar(window_t *w, enum button_status status,
sfVector2i mouse);

void event_keypressed(window_t *w, sfEvent *event);
void event_window_close(window_t *w);

void resize_shortcut(window_t *w, sfEvent *event, int coeff);

// ACTION

void action_manager(window_t *w);
void action_show_click(window_t *w);
void action_mouse_wheel_clicked(window_t *w);
void action_mouse_left_clicked(window_t *w);

void action_map_save(window_t *w);
void action_map_load(window_t *w);
void update_mape_name(window_t *w, char *new_name);
void update_select_mode(window_t *w);

void gui_button_tool_reset_state(ui_t *ui);
int action_gui_button_tool(button_t *button, state_t *state, ui_t *ui,
enum tools tool);

void change_texture_display_mode(window_t *w);

void action_object_move(window_t *w, sfEvent *event);

#endif
