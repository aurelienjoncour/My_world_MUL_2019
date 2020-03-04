/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slider_get_value
*/

#include "my_world.h"

float slider_get_value(slider_t *slider)
{
    float position = slider->circle_pos.x - slider->min;
    float length = slider->max - slider->min;

    return 1 + (position / length * 10);
}