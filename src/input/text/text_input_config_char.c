/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** text input
*/

#include "my_world.h"

int text_input_set_charsize(text_in_t *in, unsigned int size)
{
    if (in) {
        in->charsize = size;
        sfText_setCharacterSize(in->text, size);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int text_input_set_font(text_in_t *in, const char *path_font)
{
    if (in && path_font) {
        sfFont_destroy(in->font);
        in->font = sfFont_createFromFile(path_font);
        if (!in->font) {
            my_putstr_error("text_input_set_font : error font create\n");
            return EXIT_FAILURE;
        }
        sfText_setFont(in->text, in->font);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
