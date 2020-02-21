/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_world.h"

static void check_event_button_headbar(window_t *w, enum button_status status,
int x, int y)
{
    if (button_poll_event(&w->ui.save, x, y, status, ACTIVE)) {
        action_map_save(w);
    }
    if (button_poll_event(&w->ui.reset, x, y, status, ACTIVE)) {
        map_reset(&w->map);
    }
    if (button_poll_event(&w->ui.load, x, y, status, NONE)) {
        action_map_load(w);
    }
    if (button_poll_event(&w->ui.change_map_name, x, y, status, NONE)) {
        text_input_run(&w->ui.edit_map_name, w->window);
        free(w->map.map_name);
        w->map.map_name = text_input_get_input(&w->ui.edit_map_name);
    }
    if (button_poll_event(&w->ui.generate_random, x, y, status, ACTIVE)) {

    }
}

static void check_event_button_rightbar(window_t *w, enum button_status status,
int x, int y)
{
    if (button_poll_event(&w->ui.help_menu, x, y, status, ACTIVE)) {

    }
    if (button_poll_event(&w->ui.scale, x, y, status, ACTIVE)) {

    }
    if (button_poll_event(&w->ui.translate, x, y, status, ACTIVE)) {

    }
    if (button_poll_event(&w->ui.rotate, x, y, status, ACTIVE)) {

    }
}

static void event_mouse_button_guibutton(window_t *w, sfEvent *event)
{
    sfMouseButton button = event->mouseButton.button;
    sfMouseButtonEvent button_evt = event->mouseButton;

    if (event->type == sfEvtMouseButtonPressed && button == sfMouseLeft) {
        check_event_button_headbar(w, ACTIVE, button_evt.x, button_evt.y);
        check_event_button_rightbar(w, ACTIVE, button_evt.x, button_evt.y);
        check_event_button_toolbar(w, ACTIVE, button_evt.x, button_evt.y);
        check_event_button_leftbar(w, ACTIVE, button_evt.x, button_evt.y);
    }
    if (event->type == sfEvtMouseButtonReleased && button == sfMouseLeft) {
        check_event_button_headbar(w, NONE, button_evt.x, button_evt.y);
        check_event_button_rightbar(w, NONE, button_evt.x, button_evt.y);
        check_event_button_toolbar(w, NONE, button_evt.x, button_evt.y);
        check_event_button_leftbar(w, NONE, button_evt.x, button_evt.y);
    }
}

void event_mouse_guibutton(window_t *w, sfEvent *event)
{

    sfMouseMoveEvent move_evt = event->mouseMove;

    if (event->type == sfEvtMouseMoved && w->evt.cursor_in_window) {
        check_event_button_headbar(w, HOVER, move_evt.x, move_evt.y);
        check_event_button_rightbar(w, HOVER, move_evt.x, move_evt.y);
        check_event_button_toolbar(w, HOVER, move_evt.x, move_evt.y);
        check_event_button_leftbar(w, HOVER, move_evt.x, move_evt.y);
    }
    event_mouse_button_guibutton(w, event);
}
