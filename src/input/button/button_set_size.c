/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** set state button
*/

#include "my_world.h"

int button_set_size(button_t *button, sfVector2f *size)
{
    if (!button && !size)
        return EXIT_FAILURE;
    if (size->x <= 0 || size->y <= 0)
        return EXIT_FAILURE;
    button->size = *size;
    return EXIT_SUCCESS;
}
