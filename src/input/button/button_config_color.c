/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** set color button
*/

int button_set_color(button_t *button, sfColor *txt, sfColor *background)
{
    if (button && (txt || background)) {
        if (txt) {
            button->color_txt = *txt;
        }
        if (background) {
            button->color_bg = *background;
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
