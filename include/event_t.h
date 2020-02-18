/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event
*/

#ifndef EVENT_T_H_
#define EVENT_T_H_

typedef struct event {
    sfBool cursor_in_window;
    sfBool mouse_left_is_clicked;
    sfBool mouse_wheel_is_clicked;
    sfVector2i mouse_click_coord;
    sfVector2i mouse_coord;
} event_t;

#endif
