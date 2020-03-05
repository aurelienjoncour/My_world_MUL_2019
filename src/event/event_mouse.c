/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_world.h"

void event_mouse_in_out_window(window_t *w, sfEvent *event)
{
    if (!event || !w)
        return;
    if (event->type == sfEvtMouseEntered) {
        w->evt.cursor_in_window = sfTrue;
    } else if (event->type == sfEvtMouseLeft) {
        w->evt.cursor_in_window = sfFalse;
    }
}

void event_mouse_button_pressed(window_t *w, sfEvent *event)
{
    sfMouseButtonEvent evt = event->mouseButton;

    w->evt.mouse_click_coord = (sfVector2i){evt.x, evt.y};
    if (event->mouseButton.button == sfMouseMiddle) {
        w->evt.mouse_wheel_is_clicked = sfTrue;
    } else if (event->mouseButton.button == sfMouseLeft) {
        if (action_mouse_guibutton(w, event)) {
            sound_manager_play(&w->sm, SOUND_CLICK);
            return;
        }
        if (w->state.tool != TEXTURE && map_edit_height(w, evt.x, evt.y)) {
            sound_manager_play(&w->sm, SOUND_CLICK);
            return;
        }
        if (w->state.tool == TEXTURE && map_edit_texture(w, evt.x, evt.y)) {
            sound_manager_play(&w->sm, SOUND_CLICK);
            return;
        }
        w->evt.mouse_left_is_clicked = sfTrue;
    }
}

void event_mouse_button_released(window_t *w, sfEvent *event)
{
    sfMouseButtonEvent evt = event->mouseButton;

    if (evt.button == sfMouseMiddle) {
        w->evt.mouse_wheel_is_clicked = sfFalse;
    } else if (evt.button == sfMouseLeft) {
        w->evt.mouse_left_is_clicked = sfFalse;
        action_mouse_guibutton(w, event);
    }
}

void event_mouse_wheel_scroll(window_t *w, sfEvent *event)
{
    sfMouseWheelScrollEvent evt = event->mouseWheelScroll;

    map_scale(&w->map, evt.delta);
    map_scale(&w->map_water, evt.delta);
}

void event_mouse_move(window_t *w, sfEvent *event)
{
    sfMouseMoveEvent evt = event->mouseMove;

    w->evt.mouse_coord.x = evt.x;
    w->evt.mouse_coord.y = evt.y;
    action_mouse_guibutton(w, event);
}
