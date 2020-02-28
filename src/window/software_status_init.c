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
    state->tool = RAISE;
    state->select_mode = TILE;
    state->map_display_mode = TXTR;
    state->help_menu = sfFalse;
}
