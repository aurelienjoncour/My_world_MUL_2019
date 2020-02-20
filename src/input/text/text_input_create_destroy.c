/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** create and destroy a text input
*/

#include "my_world.h"

extern const sfVector2f TEXT_IN_INIT_POS;
extern const unsigned int TEXT_IN_INIT_CHARSIZE;
extern const sfColor TEXT_IN_INIT_TXTCOLOR;
extern const sfColor TEXT_IN_INIT_BGCOLOR;
extern const char *TEXT_IN_INIT_FONT;

void text_input_destroy(text_in_t *input)
{
    if (!input)
        return;
    free(input->buffer);
    free(input->title);
    sfText_destroy(input->text);
    sfFont_destroy(input->font);
}

static int text_input_create_text(text_in_t *input)
{
    input->font = sfFont_createFromFile(TEXT_IN_INIT_FONT);
    input->text = sfText_create();
    if (!input->text || !input->font) {
        my_putstr_error("text_input_create : error text or font object\n");
        return EXIT_FAILURE;
    }
    sfText_setFont(input->text, input->font);
    sfText_setPosition(input->text, TEXT_IN_INIT_POS);
    sfText_setString(input->text, input->buffer);
    sfText_setColor(input->text, TEXT_IN_INIT_TXTCOLOR);
    sfText_setCharacterSize(input->text, TEXT_IN_INIT_CHARSIZE);
    return EXIT_SUCCESS;
}

int text_input_create(text_in_t *input, const char *title,
unsigned int max_char, const char *init_buffer)
{
    if (!input || max_char > 100)
        return EXIT_FAILURE;
    input->max_char = max_char + 2;
    input->title = my_strdup(title);
    input->window = NULL;
    input->buffer = malloc(sizeof(char) * input->max_char);
    if (!input->buffer || !input->title) {
        my_putstr_error("txt_input_create: malloc error\n");
        return EXIT_FAILURE;
    }
    my_strcpy(input->buffer, ">");
    my_strncpy(input->buffer + 1, init_buffer, max_char);
    input->i_buffer = 1 + my_strlen(init_buffer);
    if (text_input_create_text(input) == EXIT_FAILURE)
        return EXIT_FAILURE;
    input->color_bg = TEXT_IN_INIT_BGCOLOR;
    input->color_txt = TEXT_IN_INIT_TXTCOLOR;
    return EXIT_SUCCESS;
}
