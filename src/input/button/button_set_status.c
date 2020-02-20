/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** change the status of a button
*/

#include "my_world.h"

void button_set_status(button_t *button, enum button_status state)
{
    if (!button)
        return;
    button->state = state;
    button_update_bg_color(button);
}
