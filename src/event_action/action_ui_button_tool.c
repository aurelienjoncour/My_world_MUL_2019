/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** execute activated events
*/

#include "event_action.h"

void gui_button_tool_reset_state(ui_t *ui)
{
    button_set_status(&ui->raise, NONE);
    button_set_status(&ui->lower, NONE);
    button_set_status(&ui->level, NONE);
    button_set_status(&ui->texture, NONE);
}

int action_gui_button_tool(button_t *button, state_t *state, ui_t *ui,
enum tools tool)
{
    state->tool = tool;
    gui_button_tool_reset_state(ui);
    button_set_status(button, ACTIVE);
    return 1;
}
