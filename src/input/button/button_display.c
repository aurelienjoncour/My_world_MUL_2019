/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** display button
*/

#include "my_world.h"

static void button_display_help_label(button_t *button, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect rect = sfText_getLocalBounds(button->help_label);
    sfVector2f position = {(float)mouse_pos.x - rect.width / 2,
    mouse_pos.y + 15};

    sfText_setPosition(button->help_label, position);
    sfRenderWindow_drawText(window, button->help_label, NULL);
}

void button_display(button_t *button, sfRenderWindow *window)
{
    if (!button)
        return;
    if (button->rect)
        sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
    if (button->text)
        sfRenderWindow_drawText(window, button->text, NULL);
    if (button->help_label) {
        if (button->state != NONE && !button->is_checkbox) {
            button_display_help_label(button, window);
        } else if (button->is_checkbox && button->state == HOVER) {
            button_display_help_label(button, window);
        }
    }
}
