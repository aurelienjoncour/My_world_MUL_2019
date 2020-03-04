/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slider_create_destroy
*/

#include "my_world.h"

int slider_create(slider_t *slider, sfVector2f position, float length)
{
    slider->circle = sfCircleShape_create();
    slider->circle_pos = (sfVector2f){position.x, position.y - 10};
    slider->rect_pos = position;
    slider->rect_size = (sfVector2f){length, 8};
    slider->circle_radius = 15;
    slider->circle_pos.x += ((length / 2) - slider->circle_radius);
    slider->isPressed = sfFalse;
    slider->rect = sfRectangleShape_create();
    slider->min = position.x;
    slider->max = slider->min + length - slider->circle_radius * 2;
    sfRectangleShape_setFillColor(slider->rect, sfRed);
    sfRectangleShape_setPosition(slider->rect, slider->rect_pos);
    sfRectangleShape_setSize(slider->rect, slider->rect_size);
    sfCircleShape_setFillColor(slider->circle, sfWhite);
    sfCircleShape_setPosition(slider->circle, slider->circle_pos);
    sfCircleShape_setRadius(slider->circle, slider->circle_radius);
    return EXIT_SUCCESS;
}

int slider_destroy(slider_t *slider)
{
    sfRectangleShape_destroy(slider->rect);
    sfCircleShape_destroy(slider->circle);
    return EXIT_SUCCESS;
}
