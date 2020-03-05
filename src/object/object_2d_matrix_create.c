/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** 2020-03-05T14:33:04+01:00 : simon
*/

#include "my_world.h"

static void object_2d_matrix_create_sub(object_t *obj, int x)
{
    for (int y = 0; y < obj->width; y++) {
        for (int z = 0; z < obj->width; z++) {
            obj->mtx_2d[z][y][x] = object_project_iso_point(obj, x, y, z);
        }
    }
}

void object_2d_matrix_create(object_t *obj)
{
    for (int x = 0; x < obj->width; x++) {
        object_2d_matrix_create_sub(obj, x);
    }
}
