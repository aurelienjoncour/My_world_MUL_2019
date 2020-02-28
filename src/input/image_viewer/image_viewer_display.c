/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** image viewer
*/

#include "my_world.h"

static void image_viewer_event_manager(img_view_t *self, sfEvent *event,
sfBool *is_active)
{
    if (event->type == sfEvtClosed) {
        image_viewer_status(self, is_active);
    } else if (event->type == sfEvtKeyPressed) {
        image_viewer_status(self, is_active);
    }
}

int image_viewer_display(img_view_t *self, sfBool *is_active)
{
    sfEvent event;

    if (!self || !self->sprite)
        return EXIT_FAILURE;
    while (sfRenderWindow_pollEvent(self->window, &event))
        image_viewer_event_manager(self, &event, is_active);
    sfRenderWindow_clear(self->window, sfBlack);
    sfRenderWindow_drawSprite(self->window, self->sprite, NULL);
    sfRenderWindow_display(self->window);
    return EXIT_SUCCESS;
}
