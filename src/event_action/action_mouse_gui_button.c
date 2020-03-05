/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Action GUI buttons
*/

#include "my_world.h"

static int event_button_pressed(window_t *w, sfEvent *event)
{
    int ret = 0;
    sfMouseButtonEvent button_evt = event->mouseButton;
    sfVector2i mouse = {.x = button_evt.x, .y = button_evt.y};
    sfMouseButton button = event->mouseButton.button;

    if (event->type == sfEvtMouseButtonPressed && button == sfMouseLeft) {
        ret += check_event_slider(&w->ui.slider, ACTIVE, mouse, w);
        ret += check_event_button_topbar(w, ACTIVE, mouse);
        ret += check_event_button_view(w, ACTIVE, mouse);
        ret += check_event_button_toolbar(w, ACTIVE, mouse);
        ret += check_event_button_leftbar(w, ACTIVE, mouse);
    }
    return ret;
}

static int event_button_released(window_t *w, sfEvent *event)
{
    int ret = 0;
    sfMouseButtonEvent button_evt = event->mouseButton;
    sfVector2i mouse = {.x = button_evt.x, .y = button_evt.y};
    sfMouseButton button = event->mouseButton.button;

    if (event->type == sfEvtMouseButtonReleased && button == sfMouseLeft) {
        ret += check_event_slider(&w->ui.slider, NONE, mouse, w);
        ret += check_event_button_topbar(w, NONE, mouse);
        ret += check_event_button_view(w, NONE, mouse);
        ret += check_event_button_leftbar(w, NONE, mouse);
        ret += check_event_button_toolbar(w, NONE, mouse);
    }
    return ret;
}

static int event_button_hover(window_t *w, sfEvent *event)
{
    sfMouseMoveEvent move_evt = event->mouseMove;
    sfVector2i mouse = {0};
    int ret = 0;

    if (event->type == sfEvtMouseMoved && w->evt.cursor_in_window) {
        mouse.x = move_evt.x;
        mouse.y = move_evt.y;
        ret += check_event_slider(&w->ui.slider, HOVER, mouse, w);
        ret += check_event_button_topbar(w, HOVER, mouse);
        ret += check_event_button_view(w, HOVER, mouse);
        ret += check_event_button_toolbar(w, HOVER, mouse);
        ret += check_event_button_leftbar(w, HOVER, mouse);
    }
    return ret;
}

int action_mouse_guibutton(window_t *w, sfEvent *event)
{
    int ret = 0;

    ret += event_button_pressed(w, event);
    ret += event_button_released(w, event);
    ret += event_button_hover(w, event);
    return ret;
}
