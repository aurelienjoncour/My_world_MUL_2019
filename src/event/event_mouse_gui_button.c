/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_world.h"

static int check_event_button_headbar_beta(window_t *w,
enum button_status status, int x, int y)
{
    if (button_poll_event(&w->ui.change_map_name, x, y, status, NONE)) {
        text_input_run(&w->ui.edit_map_name, w->window);
        update_mape_name(w, text_input_get_input(&w->ui.edit_map_name));
        return 1;
    }
    if (button_poll_event(&w->ui.generate_random, x, y, status, ACTIVE)) {
        map_generator(&w->map);
        return 1;
    }
    return 0;
}

static int check_event_button_headbar_alpha(window_t *w,
enum button_status status, int x, int y)
{
    if (button_poll_event(&w->ui.save, x, y, status, ACTIVE)) {
        action_map_save(w);
        return 1;
    }
    if (button_poll_event(&w->ui.reset, x, y, status, ACTIVE)) {
        map_reset(&w->map);
        return 1;
    }
    if (button_poll_event(&w->ui.load, x, y, status, NONE)) {
        action_map_load(w);
        return 1;
    }
    return 0;
}

static int check_event_button_rightbar(window_t *w, enum button_status status,
int x, int y)
{
    if (button_poll_event(&w->ui.help_menu, x, y, status, NONE)) {
        image_viewer_run(&w->ui.help_menu_viewer, w->window);
        return 1;
    }
    if (button_poll_event(&w->ui.scale, x, y, status, ACTIVE)) {

        return 1;
    }
    if (button_poll_event(&w->ui.translate, x, y, status, ACTIVE)) {

        return 1;
    }
    if (button_poll_event(&w->ui.rotate, x, y, status, ACTIVE)) {

        return 1;
    }
    return 0;
}

static int event_mouse_button_guibutton(window_t *w, sfEvent *event)
{
    sfMouseButton button = event->mouseButton.button;
    sfMouseButtonEvent button_evt = event->mouseButton;
    int ret = 0;

    if (event->type == sfEvtMouseButtonPressed && button == sfMouseLeft) {
        ret += check_event_button_headbar_alpha(w, ACTIVE, button_evt.x,
        button_evt.y);
        ret += check_event_button_headbar_beta(w, ACTIVE, button_evt.x, button_evt.y);
        ret += check_event_button_rightbar(w, ACTIVE, button_evt.x, button_evt.y);
        ret += check_event_button_toolbar(w, ACTIVE, button_evt.x, button_evt.y);
        ret += check_event_button_leftbar(w, ACTIVE, button_evt.x, button_evt.y);
    }
    if (event->type == sfEvtMouseButtonReleased && button == sfMouseLeft) {
        ret += check_event_button_headbar_alpha(w, NONE, button_evt.x, button_evt.y);
        ret += check_event_button_headbar_beta(w, NONE, button_evt.x, button_evt.y);
        ret += check_event_button_rightbar(w, NONE, button_evt.x, button_evt.y);
        ret += check_event_button_toolbar(w, NONE, button_evt.x, button_evt.y);
        ret += check_event_button_leftbar(w, NONE, button_evt.x, button_evt.y);
    }
    return ret;
}

int event_mouse_guibutton(window_t *w, sfEvent *event)
{
    int ret = 0;
    sfMouseMoveEvent move_evt = event->mouseMove;

    if (event->type == sfEvtMouseMoved && w->evt.cursor_in_window) {
        ret += check_event_button_headbar_alpha(w, HOVER, move_evt.x, move_evt.y);
        ret += check_event_button_headbar_beta(w, HOVER, move_evt.x, move_evt.y);
        ret += check_event_button_toolbar(w, HOVER, move_evt.x, move_evt.y);
        ret += check_event_button_leftbar(w, HOVER, move_evt.x, move_evt.y);
    }
    ret += event_mouse_button_guibutton(w, event);
    return ret;
}
