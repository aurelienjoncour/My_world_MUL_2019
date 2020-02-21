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

int text_input_set_content(text_in_t *in, const char *str)
{
    int len = my_strlen(str);

    if (in) {
        if (len > (int)in->max_char)
            len = in->max_char - 1;
        my_strncpy(in->buffer + 1, str, in->max_char - 2);
        in->buffer[len + 1] = '\0';
        sfText_setString(in->text, in->buffer);
        in->i_buffer = my_strlen(str);
        if (in->i_buffer > (int)in->max_char)
            in->i_buffer = in->max_char;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
