/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Action GUI buttons top of the window
*/

#include "my_world.h"

static int check_event_button_headbar_beta(window_t *w,
enum button_status status, sfVector2i mouse)
{
    if (button_poll_event(&w->ui.change_map_name, mouse, status, NONE)) {
        text_input_run(&w->ui.edit_map_name, w->window);
        update_mape_name(w, text_input_get_input(&w->ui.edit_map_name));
        return 1;
    }
    if (button_poll_event(&w->ui.generate_random, mouse, status, ACTIVE)) {
        map_generator(&w->map);
        return 1;
    }
    return 0;
}

static int check_event_button_headbar_alpha(window_t *w,
enum button_status status, sfVector2i mouse)
{
    if (button_poll_event(&w->ui.save, mouse, status, ACTIVE)) {
        action_map_save(w);
        return 1;
    }
    if (button_poll_event(&w->ui.reset, mouse, status, ACTIVE)) {
        map_reset(&w->map);
        return 1;
    }
    if (button_poll_event(&w->ui.load, mouse, status, NONE)) {
        action_map_load(w);
        return 1;
    }
    return 0;
}

int check_event_button_topbar(window_t *w, enum button_status status,
sfVector2i mouse)
{
    int ret = 0;

    if (button_poll_event(&w->ui.help_menu, mouse, status, ACTIVE)) {
        image_viewer_status(&w->ui.help_menu_viewer, &w->state.help_menu);
        ret += 1;
    }
    ret += check_event_button_headbar_beta(w, status, mouse);
    ret += check_event_button_headbar_alpha(w, status, mouse);
    return ret;
}
