/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** check if coords are hover a button and change it state.
*/

#include "my_world.h"

static sfBool button_check_coordinate(button_t *button, int x, int y)
{
    if (x < button->position.x || x > button->position.x + button->size.x) {
        if (button->state == HOVER) {
            button->state = NONE;
            button_update_bg_color(button);
        }
        return sfFalse;
    }
    if (y < button->position.y || y > button->position.y + button->size.y) {
        if (button->state == HOVER) {
            button->state = NONE;
            button_update_bg_color(button);
        }
        return sfFalse;
    }
    return sfTrue;
}

sfBool button_poll_event(button_t *button, sfVector2i mouse,
enum button_status state, enum button_status active_status)
{
    if (!button)
        return sfFalse;
    else if (!button_check_coordinate(button, mouse.x, mouse.y))
        return sfFalse;
    if (state != ACTIVE && button->state == ACTIVE && button->is_checkbox)
        state = ACTIVE;
    else if (state == ACTIVE && button->state == ACTIVE && button->is_checkbox)
        state = NONE;
    button->state = state;
    if (state == NONE)
        button->state = HOVER;
    button_update_bg_color(button);
    if (state == active_status || (button->is_checkbox && state != HOVER))
        return sfTrue;
    return sfFalse;
}
