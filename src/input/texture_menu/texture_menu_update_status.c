/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** texture_menu
*/

#include "my_world.h"

int texture_menu_status(texture_menu_t *self, sfBool *state)
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
