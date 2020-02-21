/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** create and destroy button
*/

#include "my_world.h"
#include "my.h"

extern const unsigned int BUTTON_INIT_CHARSIZE;
extern const sfColor BUTTON_INIT_COLORBG;
extern const sfColor BUTTON_INIT_COLORTXT;
extern const sfColor BUTTON_INIT_COLORHOV;
extern const sfColor BUTTON_INIT_COLORACT;
extern const char *BUTTON_INIT_FONT;

void button_destroy(button_t *button)
{
    free(button->label);
    sfFont_destroy(button->font);
    sfText_destroy(button->text);
    sfRectangleShape_destroy(button->rect);
    button->is_disabled = sfTrue;
}

static int button_create_text(button_t *button, const sfVector2f *position,
const char *label)
{
    button->text = sfText_create();
    if (!button->text) {
        my_putstr_error("Error : create text object (button create)\n");
        return EXIT_FAILURE;
    }
    button->char_size = BUTTON_INIT_CHARSIZE;
    button->font = sfFont_createFromFile(BUTTON_INIT_FONT);
    if (!button->font) {
        my_putstr_error("Error : load font (button create)\n");
        return EXIT_FAILURE;
    }
    sfText_setCharacterSize(button->text, button->char_size);
    sfText_setColor(button->text, button->color_txt);
    sfText_setFont(button->text, button->font);
    sfText_setPosition(button->text, *position);
    //sfText_setString(button->text, button->label);
    button_set_label(button, label);
    return EXIT_SUCCESS;
}

static int button_create_rectangle(button_t *button,
const sfVector2f *position, const sfVector2f *size)
{
    button->rect = sfRectangleShape_create();
    if (!button->rect) {
        my_putstr_error("Error : create rectangle object (button create)\n");
        return EXIT_FAILURE;
    }
    sfRectangleShape_setFillColor(button->rect, BUTTON_INIT_COLORBG);
    sfRectangleShape_setPosition(button->rect, *position);
    sfRectangleShape_setSize(button->rect, *size);
    return EXIT_SUCCESS;
}

static int button_create_init(button_t *button, const sfVector2f *size,
const sfVector2f *position)
{
    button->label = NULL;
    button->color_bg = BUTTON_INIT_COLORBG;
    button->color_txt = BUTTON_INIT_COLORTXT;
    button->color_hover = BUTTON_INIT_COLORHOV;
    button->color_active = BUTTON_INIT_COLORACT;
    button->position = *position;
    button->size = *size;
    button->is_disabled = sfFalse;
    button->is_checkbox = sfFalse;
    button->state = NONE;
    return EXIT_SUCCESS;
}

int button_create(button_t *button, const char *label, const sfVector2f *size,
const sfVector2f *position)
{
    if (button_create_init(button, size, position) == EXIT_ERROR)
        return EXIT_FAILURE;
    if (button_create_text(button, position, label) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (button_create_rectangle(button, position, size) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
