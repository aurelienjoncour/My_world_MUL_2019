/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** image viewer
*/

#include "my_world.h"

int image_viewer_create(img_view_t *self, const char *file_name,
const char *title)
{
    if (self && file_name) {
        self->title = my_strdup(title);
        self->file_path = my_strdup(file_name);
        self->texture = sfTexture_createFromFile(file_name, NULL);
        if (!self->texture || !self->title || !self->file_path) {
            my_putstr_error("image_viewer_create : error\n");
            self->sprite = NULL;
            return EXIT_FAILURE;
        }
        self->sprite = sfSprite_create();
        sfSprite_setTexture(self->sprite, self->texture, sfTrue);
        self->window = NULL;
        self->size = sfTexture_getSize(self->texture);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

void image_viewer_destroy(img_view_t *self)
{
    sfTexture_destroy(self->texture);
    sfSprite_destroy(self->sprite);
    free(self->title);
    free(self->file_path);
}
