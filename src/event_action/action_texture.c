/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** action => texture
*/

#include "event_action.h"

void change_texture_display_mode(window_t *w)
{
    switch (w->state.map_display_mode) {
        case TXTR:
            w->state.map_display_mode = LINE;
            break;
        case LINE:
            w->state.map_display_mode = BOTH;
            break;
        case BOTH:
            w->state.map_display_mode = TXTR;
            break;
    }
}
