/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
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

static int check_event_button_rightbar(window_t *w, enum button_status status,
sfVector2i mouse)
{
    if (button_poll_event(&w->ui.help_menu, mouse, status, NONE)) {
        image_viewer_run(&w->ui.help_menu_viewer, w->window);
        return 1;
    }
    if (button_poll_event(&w->ui.scale, mouse, status, ACTIVE)) {

        return 1;
    }
    if (button_poll_event(&w->ui.translate, mouse, status, ACTIVE)) {

        return 1;
    }
    if (button_poll_event(&w->ui.rotate, mouse, status, ACTIVE)) {

        return 1;
    }
    return 0;
}

static int event_mouse_button_guibutton(window_t *w, sfEvent *event)
{
    sfMouseButton button = event->mouseButton.button;
    sfMouseButtonEvent button_evt = event->mouseButton;
    sfVector2i mouse = {.x = button_evt.x, .y = button_evt.y};
    int ret = 0;

    if (event->type == sfEvtMouseButtonPressed && button == sfMouseLeft) {
        ret += check_event_button_headbar_alpha(w, ACTIVE, mouse);
        ret += check_event_button_headbar_beta(w, ACTIVE, mouse);
        ret += check_event_button_rightbar(w, ACTIVE, mouse);
        ret += check_event_button_toolbar(w, ACTIVE, mouse);
        ret += check_event_button_leftbar(w, ACTIVE, mouse);
    }
    if (event->type == sfEvtMouseButtonReleased && button == sfMouseLeft) {
        ret += check_event_button_headbar_alpha(w, NONE, mouse);
        ret += check_event_button_headbar_beta(w, NONE, mouse);
        ret += check_event_button_toolbar(w, NONE, mouse);
        ret += check_event_button_rightbar(w, NONE, mouse);
        ret += check_event_button_leftbar(w, NONE, mouse);
    }
    return ret;
}

int event_mouse_guibutton(window_t *w, sfEvent *event)
{
    int ret = 0;
    sfMouseMoveEvent move_evt = event->mouseMove;
    sfVector2i mouse = {0};

    if (event->type == sfEvtMouseMoved && w->evt.cursor_in_window) {
        mouse.x = move_evt.x;
        mouse.y = move_evt.y;
        ret += check_event_button_headbar_alpha(w, HOVER, mouse);
        ret += check_event_button_headbar_beta(w, HOVER, mouse);
        ret += check_event_button_rightbar(w, HOVER, mouse);
        ret += check_event_button_toolbar(w, HOVER, mouse);
        ret += check_event_button_leftbar(w, HOVER, mouse);
    }
    ret += event_mouse_button_guibutton(w, event);
    return ret;
}
