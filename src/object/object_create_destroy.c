/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** object
*/

#include "my_world.h"

static sfVertexArray *create_line(object_t *obj, sfVector2f *point1,
sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = map->color_line};
    sfVertex vertex2 = {.position = *point2, .color = map->color_line};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return vertex_array;
}

static int object_vertex_create(object_t *obj)
{
    sfVector2f ***mtx_2d = obj->matrix_2d;
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 1; x++) {
            obj->vrtx_x[y][x] = create_line(map, &mtx_2d[0][x][y],
            &mtx_2d[y][x + 1]);
            obj->vrtx_y[y][x] = create_line(map, &mtx_2d[y][x],
            &mtx_2d[y][x + 1]);
            obj->vrtx_z[y][x] = create_line(map, &mtx_2d[y][x],
            &mtx_2d[y][x + 1]);
        }
    }
}

static int object_matrix2d_create(object_t *obj)
{
    for (int z = 0; z < obj->height; z++) {
        for (int y = 0; y < obj->width; y++) {
            for (int x = 0; x < obj->width; x++) {
                obj->matrix_2d[z][y][x] = obj_project_iso_point(x, y, y, obj);
            }
        }
    }
    return EXIT_SUCCESS;
}

int object_create(object_t *obj)
{
    obj->sampling = (sfVector3f){64, 64, 64};
    obj->angle = (sfVector2f){45, 45};
    obj->origin = (sfVector2f){100, 100};
    obj->height = 2;
    obj->width = 2;
    obj->modified = sfFalse;
    obj->color_line = sfWhite;
    object_matrix2d_create(obj);

}
