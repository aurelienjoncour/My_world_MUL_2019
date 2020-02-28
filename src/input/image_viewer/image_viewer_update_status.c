/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** image viewer
*/

#include "my_world.h"

int image_viewer_status(img_view_t *self, sfBool *state)
{
    if (!self)
        return EXIT_FAILURE;
    *state = !(*state);
    sfRenderWindow_setVisible(self->window, *state);
    if (*state) {
        sfRenderWindow_setActive(self->window, sfTrue);
        sfRenderWindow_requestFocus(self->window);
    }
    return EXIT_SUCCESS;
}
