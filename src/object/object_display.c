/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-05T14:51:13+01:00 | Author: SimonRacaud
*/

#include "my_world.h"

static void object_display_texture(object_t *obj, sfRenderWindow *win)
{
    for (int i = 0; i < 3; i++) {
        obj->render_state.texture = obj->textures[i];
        sfRenderWindow_drawVertexArray(win, obj->vrtx_txr_a[i],
        &obj->render_state);
        sfRenderWindow_drawVertexArray(win, obj->vrtx_txr_b[i],
        &obj->render_state);
    }
}

static void object_display_lines_sub(object_t *obj, sfRenderWindow *win, int x,
int y)
{
    for (int z = 0; z < obj->width; z++) {
        if (x < obj->width - 1)
            sfRenderWindow_drawVertexArray(win, obj->vrtx_x[z][y][x], NULL);
        if (z < obj->width - 1)
            sfRenderWindow_drawVertexArray(win, obj->vrtx_z[z][y][x], NULL);
        if (y < obj->width - 1)
            sfRenderWindow_drawVertexArray(win, obj->vrtx_y[z][y][x], NULL);
    }
}

int object_display(object_t *obj, sfRenderWindow *win)
{
    if (!obj)
        return EXIT_FAILURE;
    if (obj->modified) {
        obj->modified = sfFalse;
        object_reload(obj);
    }
    object_display_texture(obj, win);
    for (int x = 0; x < obj->width; x++) {
        for (int y = 0; y < obj->width; y++) {
            object_display_lines_sub(obj, win, x, y);
        }
    }
    return EXIT_SUCCESS;
}
