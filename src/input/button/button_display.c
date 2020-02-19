/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** display button
*/

void button_display(button_t *button, sfRenderWindow *window)
{
    if (!button)
        return;
    if (button->rect)
        sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
    if (button->text)
        sfRenderWindow_drawText(window, button->text, NULL);
}
