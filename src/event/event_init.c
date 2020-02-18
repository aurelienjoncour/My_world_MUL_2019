/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "event.h"

void event_init(event_t *evt)
{
    evt->cursor_in_window = sfTrue;
    evt->mouse_left_is_clicked = sfFalse;
    evt->mouse_wheel_is_clicked = sfFalse;
    evt->mouse_click_coord.x = 0;
    evt->mouse_click_coord.y = 0;
    evt->mouse_coord.x = 0;
    evt->mouse_coord.y = 0;
}
