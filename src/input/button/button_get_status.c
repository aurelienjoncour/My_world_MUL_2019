/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** get state of button
*/

#include "my_world.h"

enum status button_get_status(button_t *button)
{
    if (button)
        return button->state;
    return NONE;
}
