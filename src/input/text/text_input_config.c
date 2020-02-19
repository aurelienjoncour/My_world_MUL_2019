/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** text input
*/

#include "my_world.h"

int text_input_set_color(text_in_t *in, sfColor *bg_color, sfColor *txt_color)
{
    if (in && bg_color && txt_color) {
        in->color_bg = *bg_color;
        in->color_txt = *txt_color;
        sfText_setColor(in->text, in->color_txt);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int text_input_set_size(text_in_t *in, unsigned int sizex, unsigned int sizey)
{
    if (in) {
        in->size.x = sizex;
        in->size.y = sizey;
        sfRenderWindow_setSize(in->window, in->size);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
