/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slider_poll_event
*/

#include "my_world.h"

int check_event_slider(slider_t *slider, enum button_status status,
sfVector2i mouse, window_t *w)
{
    int shift = 0;

    if (point_is_on_circle(mouse, slider->circle_radius, slider->circle_pos))
        if (status == ACTIVE && !slider->isPressed)
            slider->isPressed = sfTrue;
    if (status == HOVER && slider->isPressed) {
        w->evt.mouse_left_is_clicked = false;
        shift = mouse.x - (slider->circle_pos.x + slider->circle_radius);
        slider->circle_pos.x += shift;
        if (slider->circle_pos.x  < slider->min)
            slider->circle_pos.x = slider->min;
        if (slider->circle_pos.x > slider->max)
            slider->circle_pos.x = slider->max;
    }
    if (status == NONE && slider->isPressed)
        slider->isPressed = sfFalse;
    return EXIT_SUCCESS;
}