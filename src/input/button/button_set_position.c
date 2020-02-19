/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** set state button
*/

#include "my_world.h"

int button_set_position(button_t *button, sfVector2f *position)
{
    if (position->x < 0 || position->y < 0)
        return EXIT_FAILURE;
    button->position = *position;
    return EXIT_SUCCESS;
}