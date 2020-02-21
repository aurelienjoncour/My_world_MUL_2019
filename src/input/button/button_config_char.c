/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** set state button
*/

#include "my_world.h"

static void button_center_label(button_t *button)
{
    sfFloatRect bound = sfText_getGlobalBounds(button->text);
    float marginx = button->size.x - bound.width;
    float marginy = (button->size.y - bound.height) / 4;

    sfText_setPosition(button->text, button->position);;
    sfText_move(button->text, (sfVector2f){marginx / 2, marginy / 2});
}

int button_set_label(button_t *button, const char *label)
{
    if (button) {
        free(button->label);
        button->label = my_strdup(label);
        sfText_setString(button->text, button->label);
        button_center_label(button);
    }
    return EXIT_SUCCESS;
}

int button_set_charsize(button_t *button, unsigned int char_size)
{
    if (button) {
        button->char_size = char_size;
        sfText_setCharacterSize(button->text, button->char_size);
    }
    return EXIT_SUCCESS;
}

int button_set_font(button_t *button, const char *path_font)
{
    if (button && path_font) {
        sfFont_destroy(button->font);
        button->font = sfFont_createFromFile(path_font);
        if (!button->font) {
            my_putstr_error("Error : load font (button set font)\n");
            return EXIT_FAILURE;
        }
        sfText_setFont(button->text, button->font);
    }
    return EXIT_SUCCESS;
}
