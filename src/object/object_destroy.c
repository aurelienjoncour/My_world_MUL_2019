/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** 2020-03-05T14:33:04+01:00 : simon
*/

#include "my_world.h"

static void object_destroy_sub(object_t *obj, int z, int y)
{
    for (int x = 0; x < obj->width; x++) {
        if (x == 0)
            sfVertexArray_destroy(obj->vrtx_x[z][y][x]);
        if (y == 0)
            sfVertexArray_destroy(obj->vrtx_y[z][y][x]);
        if (z == 0)
            sfVertexArray_destroy(obj->vrtx_z[z][y][x]);
    }
}

void object_destroy(object_t *obj)
{
    for (int z = 0; z < obj->width; z++) {
        for (int y = 0; y < obj->width; y++) {
            object_destroy_sub(obj, z, y);
        }
    }
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(obj->textures[i]);
        sfVertexArray_destroy(obj->vrtx_txr_a[i]);
        sfVertexArray_destroy(obj->vrtx_txr_b[i]);
    }
}
