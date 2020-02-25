/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** action => texture
*/

#include "event_action.h"

void change_texture_display_mode(window_t *w)
{
    w->state.map_show_texture = !w->state.map_show_texture;
}
