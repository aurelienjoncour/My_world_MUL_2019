/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slider_display
*/

#include "my_world.h"

void slider_display(slider_t *slider, sfRenderWindow *window)
{
    if (slider->rect)
        sfRenderWindow_drawRectangleShape(window, slider->rect, NULL);
    if (slider->circle) {
        sfCircleShape_setPosition(slider->circle,
        (sfVector2f){slider->circle_pos.x, slider->circle_pos.y});
        sfRenderWindow_drawCircleShape(window, slider->circle, NULL);
    }
}
