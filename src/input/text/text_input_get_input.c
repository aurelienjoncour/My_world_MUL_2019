/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** text input
*/

#include "my_world.h"

char *text_input_get_input(text_in_t *input)
{
    return (input->buffer + 1);
}
