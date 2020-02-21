/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** image viewer
*/

#include "my_world.h"

extern const int WIN_BPP;
extern const unsigned int WIN_FRAMERATE;

static void image_viewer_event_manager(img_view_t *self, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(self->window);
    } else if (event->type == sfEvtKeyPressed) {
        sfRenderWindow_close(self->window);
    }
}

static int image_viewer_create_window(img_view_t *self)
{
    sfVideoMode mode = {self->size.x, self->size.y, WIN_BPP};

    self->window = sfRenderWindow_create(mode, self->title, sfClose,
    sfContextDefault);
    if (!self->window) {
        my_putstr_error("image_viewer_create_window : error.\n");
        return EXIT_FAILURE;
    }
    sfRenderWindow_setFramerateLimit(self->window, WIN_FRAMERATE);
    return EXIT_SUCCESS;
}

int image_viewer_run(img_view_t *self, sfRenderWindow *parent_window)
{
    sfEvent event;

    if (!self || !parent_window || !self->sprite)
        return EXIT_FAILURE;
    if (image_viewer_create_window(self) == EXIT_FAILURE)
        return EXIT_FAILURE;
    sfRenderWindow_setVisible(parent_window, sfFalse);
    while (sfRenderWindow_isOpen(self->window)) {
        while (sfRenderWindow_pollEvent(self->window, &event))
            image_viewer_event_manager(self, &event);
        sfRenderWindow_clear(self->window, sfBlack);
        sfRenderWindow_drawSprite(self->window, self->sprite, NULL);
        sfRenderWindow_display(self->window);
    }
    sfRenderWindow_setVisible(parent_window, sfTrue);
    sfRenderWindow_destroy(self->window);
    return EXIT_SUCCESS;
}
