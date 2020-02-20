/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "event_action.h"

static void (* const EVENT_HANDLER[])(window_t *, sfEvent *) =
{
    &event_mouse_button_pressed,
    &event_mouse_button_released,
    &event_mouse_wheel_scroll,
    &event_keypressed,
    &event_resize_window,
    &event_mouse_move,
    &event_mouse_in_out_window,
    &event_mouse_in_out_window
};

static const sfEventType EVENT_TYPE[] =
{
    sfEvtMouseButtonPressed,
    sfEvtMouseButtonReleased,
    sfEvtMouseWheelScrolled,
    sfEvtKeyPressed,
    sfEvtResized,
    sfEvtMouseMoved,
    sfEvtMouseEntered,
    sfEvtMouseLeft
};

static int EVENT_ARRAY_SIZE = 8;

void event_manager(window_t *w, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        event_window_close(w);
        return;
    }
    for (int i = 0; i < EVENT_ARRAY_SIZE; i++) {
        if (EVENT_TYPE[i] == event->type) {
            EVENT_HANDLER[i](w, event);
            break;
        }
    }
}
