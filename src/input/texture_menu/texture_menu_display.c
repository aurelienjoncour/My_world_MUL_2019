/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** texture menu
*/

#include "my_world.h"

static void switch_selected_texture(texture_menu_t *self, int sens)
{
    if (sens != -1 && sens != 1)
        return;
    *(self->select_idx) += sens;
    if (*(self->select_idx) < 1)
        *(self->select_idx) = self->count_sprite;
    else if (*(self->select_idx) > self->count_sprite)
        *(self->select_idx) = 1;
    sfSprite_setTexture(self->spr_selected,
    self->map->textures[(*self->select_idx)], sfFalse);
}

static void texture_menu_event_manager(texture_menu_t *self, sfEvent *event,
sfBool *is_active)
{
    if (event->type == sfEvtClosed) {
        texture_menu_status(self, is_active);
    } else if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyEscape)
            texture_menu_status(self, is_active);
        if (event->key.code == sfKeyLeft) {
            switch_selected_texture(self, -1);
        } else if (event->key.code == sfKeyRight) {
            switch_selected_texture(self, 1);
        }
    }
}

int texture_menu_display(texture_menu_t *self, sfBool *is_active)
{
    sfEvent event;

    if (!self || !is_active)
        return EXIT_FAILURE;
    while (sfRenderWindow_pollEvent(self->window, &event))
        texture_menu_event_manager(self, &event, is_active);
    sfRenderWindow_clear(self->window, self->color_bg);
    sfRenderWindow_drawSprite(self->window, self->spr_selected, NULL);
    for (int i = 0; i < self->count_sprite; i++) {
        sfRenderWindow_drawSprite(self->window, self->spr_available[i], NULL);
    }
    sfRenderWindow_drawText(self->window, self->txt_info, NULL);
    sfRenderWindow_display(self->window);
    return EXIT_SUCCESS;
}
