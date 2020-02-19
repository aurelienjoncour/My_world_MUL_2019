/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** set state button
*/

int button_set_locked(button_t *button, sfBool is_disabled)
{
    if (button) {
        button->is_disabled = is_disabled;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int button_set_ischeckbox(button_t *button, sfBool is_checkbox)
{
    if (button) {
        button->is_checkbox = is_checkbox;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
