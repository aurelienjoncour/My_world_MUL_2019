/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** text input
*/

#include "my_world.h"

static const sfKeyCode KEY_ENTER = 58;

static void text_input_keypressed(text_in_t *in, sfKeyCode code)
{
    if (code == sfKeyBack) {

    } else if (code == KEY_ENTER) {
        sfRenderWindow_close(in->window);
    }
    // other key
}

static void text_input_event_manager(text_in_t *in, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(in->window);
    } else if (event->type == sfEvtKeyPressed) {
        text_input_keypressed(in, event->key.code);
    }
}

int text_input_run(text_in_t *in)
{
    sfEvent event;
    sfVector2i pos = {700, 400};

    sfRenderWindow_setPosition(in->window, pos);
    while (sfRenderWindow_isOpen(in->window)) {
        while (sfRenderWindow_pollEvent(in->window, &event))
            text_input_event_manager(in, &event);
        sfRenderWindow_clear(in->window, in->color_bg);
        sfRenderWindow_drawText(in->window, in->text, NULL);
        sfRenderWindow_display(in->window);
    }
    return EXIT_SUCCESS;
}
