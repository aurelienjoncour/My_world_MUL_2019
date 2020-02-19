/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** set color button
*/

#include "my_world.h"

void button_update_bg_color(button_t *button)
{
    if (!button)
        return;
    if (button->state == NONE) {
        sfRectangleShape_setFillColor(button->rect, button->color_bg);
    } else if (button->state == HOVER) {
        sfRectangleShape_setFillColor(button->rect, button->color_hover);
    }
    if (button->state == ACTIVE) {
        sfRectangleShape_setFillColor(button->rect, button->color_active);
    }
}

int button_set_color(button_t *button, sfColor *txt, sfColor *background)
{
    if (button && (txt || background)) {
        if (txt) {
            button->color_txt = *txt;
            sfText_setColor(button->text, button->color_txt);
        }
        if (background) {
            button->color_bg = *background;
            button_update_bg_color(button);
        }
        return EXIT_SUCCESS;
    }
    return EXIT_ERROR;
}

int button_set_color_evt(button_t *button, sfColor *hover, sfColor *active)
{
    if (button && (hover || active)) {
        if (hover) {
            button->color_txt = *hover;
        }
        if (active) {
            button->color_bg = *active;
        }
        return EXIT_SUCCESS;
    }
    return EXIT_ERROR;
}
