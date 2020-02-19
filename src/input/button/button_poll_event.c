/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** check if coords are hover a button and change it state.
*/

#include "my_world.h"

sfBool button_poll_event(button_t *button, int x, int y, enum status state)
{
    if (!button)
        return sfFalse;
    if (x < button->position.x || x > button->position.x + button->size.x)
        return sfFalse;
    if (y < button->position.y || y > button->position.y + button->size.y)
        return sfFalse;
    button->state = state;
    button_update_bg_color(button);
    return sfTrue;
}
