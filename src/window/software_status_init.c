/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** init sofware status struct of window_t
*/

#include "my_world.h"

void soft_state_init(state_t *state)
{
    state->vmode = NONE;
    state->show_help_menu = sfFalse;
    state->map_random_gen = sfFalse;
    state->map_edit_name = sfFalse;
    state->map_load = sfFalse;
    state->map_save = sfFalse;
    state->map_reset = sfFalse;
    state->tool = NONE;
    state->map_size_x = NONE;
    state->map_size_y = NONE;
    state->select_mode = CORNER;
}
