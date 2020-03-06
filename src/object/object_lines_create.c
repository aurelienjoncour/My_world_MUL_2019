/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** 2020-03-05T14:33:04+01:00 : simon
*/

#include "my_world.h"

static sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2,
sfColor color)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = color};
    sfVertex vertex2 = {.position = *point2, .color = color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return vertex_array;
}

static void object_lines_create_sub(object_t *obj, int z, int y)
{
    for (int x = 0; x < obj->width; x++) {
        if (x == 0 && (z || y)) {
            obj->vrtx_x[z][y][x] = create_line(&obj->mtx_2d[z][y][x],
            &obj->mtx_2d[z][y][x + 1], obj->line_color);
        } else if (x == 0)
            obj->vrtx_x[z][y][x] = create_line(&obj->mtx_2d[z][y][x],
            &obj->mtx_2d[z][y][x + 1], (sfColor){255, 255, 255, 100});
        if (z == 0 && (x || y)) {
            obj->vrtx_z[z][y][x] = create_line( &obj->mtx_2d[z][y][x],
            &obj->mtx_2d[z + 1][y][x], obj->line_color);
        } else if (z == 0)
            obj->vrtx_z[z][y][x] = create_line(&obj->mtx_2d[z][y][x],
            &obj->mtx_2d[z + 1][y][x], (sfColor){255, 255, 255, 100});
        if (y == 0 && (x || z)) {
            obj->vrtx_y[z][y][x] = create_line(&obj->mtx_2d[z][y][x],
            &obj->mtx_2d[z][y + 1][x], obj->line_color);
        } else if (y == 0)
            obj->vrtx_y[z][y][x] = create_line(&obj->mtx_2d[z][y][x],
            &obj->mtx_2d[z][y + 1][x], (sfColor){255, 255, 255, 100});
    }
}

int object_lines_create(object_t *obj)
{
    for (int z = 0; z < obj->width; z++) {
        for (int y = 0; y < obj->width; y++) {
            object_lines_create_sub(obj, z, y);
        }
    }
    return EXIT_SUCCESS;
}
