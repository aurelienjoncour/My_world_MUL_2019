/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** 2020-03-05T14:33:04+01:00 : simon
*/

#include "my_world.h"

static void object_init(object_t *obj, sfVector2f *position,
sfVector3f *sampling, const char **img_path)
{
    obj->width = 2;
    if (!sampling)
        obj->size = (sfVector3f){100, 100, 100};
    else
        obj->size = *sampling;
    obj->angle = (sfVector2f){0, 45};
    if (!position)
        obj->origin = (sfVector2f){200, 400};
    else
        obj->origin = *position;
    obj->line_color = sfWhite;
    obj->path_img = img_path;
    obj->modified = sfFalse;
    obj->coord_map = (sfVector2i){1, 1};
}

int object_create(object_t *obj, sfVector2f *position, sfVector3f *sampling,
const char **img_path)
{
    if (!obj)
        return EXIT_FAILURE;
    object_init(obj, position, sampling, img_path);
    object_2d_matrix_create(obj);
    object_lines_create(obj);
    if (object_texture_create(obj, img_path) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
