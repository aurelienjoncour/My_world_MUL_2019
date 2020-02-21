/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** action => update text gui
*/

#include "event_action.h"

void update_mape_name(window_t *w, char *new_name)
{
    free(w->map.map_name);
    w->map.map_name = new_name;
    text_input_set_content(&w->ui.edit_map_name, w->map.map_name);
    text_input_set_content(&w->ui.load_map_file, w->map.map_name);
    sfText_setString(w->ui.txt_map_name, w->map.map_name);
}

void update_select_mode(window_t *w)
{
    switch (w->state.select_mode) {
        case TILE:
            sfText_setString(w->ui.txt_select_mode, "CORNER");
            w->state.select_mode = CORNER;
            break;
        case CORNER:
            sfText_setString(w->ui.txt_select_mode, "AREA");
            w->state.select_mode = AREA;
            break;
        case AREA:
            sfText_setString(w->ui.txt_select_mode, "TILE");
            w->state.select_mode = TILE;
            break;
    }
}
