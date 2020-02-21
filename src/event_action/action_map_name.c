/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** action => map name
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
