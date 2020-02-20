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
extern const unsigned int TEXT_IN_INIT_HEIGHT;
extern const unsigned int TEXT_IN_INIT_CHAR_WIDTH;
extern const unsigned int TEXT_IN_INIT_WIN_FPS;
extern const int WIN_BPP;

void text_input_destroy(text_in_t *input)
{
    if (!input)
        return;
    free(input->buffer);
    free(input->title);
    sfText_destroy(input->text);
    sfFont_destroy(input->font);
    sfRenderWindow_destroy(input->window);
}

extern int text_input_create_text(text_in_t *input)
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

extern int text_input_create_window(text_in_t *input)
{
    sfVideoMode mode = {0, TEXT_IN_INIT_HEIGHT, WIN_BPP};

    mode.width = TEXT_IN_INIT_CHAR_WIDTH * input->max_char;
    input->window = sfRenderWindow_create(mode, input->title, sfTitlebar,
    sfContextDefault);
    if (!input->window) {
        my_putstr_error("text_input_create : error create window object.\n");
        return EXIT_FAILURE;
    }
    sfRenderWindow_setMouseCursorVisible(input->window, sfFalse);
    sfRenderWindow_setFramerateLimit(input->window, TEXT_IN_INIT_WIN_FPS);
    return EXIT_SUCCESS;
}

int text_input_create(text_in_t *input, const char *title,
unsigned int max_char)
{
    if (!input || max_char > 100)
        return EXIT_FAILURE;
    input->max_char = max_char + 2;
    input->title = my_strdup(title);
    input->buffer = malloc(sizeof(char) * input->max_char);
    if (!input->buffer || !input->title) {
        my_putstr_error("txt_input_create: malloc error\n");
        return EXIT_FAILURE;
    }
    my_strcpy(input->buffer, ">");
    input->i_buffer = 1;
    if (text_input_create_text(input) == EXIT_FAILURE)
        return EXIT_FAILURE;
    input->color_bg = TEXT_IN_INIT_BGCOLOR;
    input->color_txt = TEXT_IN_INIT_TXTCOLOR;
    if (text_input_create_window(input) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
