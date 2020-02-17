/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_2d_map
*/

#include "my_world.h"

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return vertex_array;
}

int draw_2d_map(sfRenderWindow *window, sfVector2f **_2d_map, int width, int height)
{
    sfVertexArray *foo;

    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width - 1; j++) {
            foo = create_line(&_2d_map[i][j], &_2d_map[i][j + 1]);
            sfRenderWindow_drawVertexArray(window, foo, NULL);
            sfVertexArray_destroy(foo);
        }
    }
    for (size_t i = 0; i < height - 1; i++) {
        for (size_t j = 0; j < width; j++) {
            foo = create_line(&_2d_map[i][j], &_2d_map[i + 1][j]);
            sfRenderWindow_drawVertexArray(window, foo, NULL);
            sfVertexArray_destroy(foo);
        }
    }
    return 0;
}