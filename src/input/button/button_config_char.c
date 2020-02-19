/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** set state button
*/

int button_set_label(button_t *button, const char *label)
{
    if (button) {
        free(button->label);
        button->label = my_strdup(label);
        sfText_setString(button->text, button->label);
    }
    return EXIT_SUCCESS;
}

int button_set_charsize(button_t *button, unsigned int char_size)
{
    if (button) {
        button->charsize = char_size;
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
