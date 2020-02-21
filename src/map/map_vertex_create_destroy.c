/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_t
*/

#include "my_world.h"

void map_vertex_destroy(map_t *map)
{
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width - 1; j++) {
            sfVertexArray_destroy(map->vrtx_x[i][j]);
        }
    }
    for (int i = 0; i < map->height; i++)
        free(map->vrtx_x[i]);
    free(map->vrtx_x);
    for (int i = 0; i < map->height - 1; i++) {
        for (int j = 0; j < map->width; j++) {
            sfVertexArray_destroy(map->vrtx_y[i][j]);
        }
    }
    for (int i = 0; i < map->height - 1; i++)
        free(map->vrtx_y[i]);
    free(map->vrtx_y);
}

static sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return vertex_array;
}

static int map_vertex_malloc(map_t *map)
{
    map->vrtx_x = malloc(sizeof(sfVertexArray **) * map->height);
    if (!map->vrtx_x)
        return EXIT_FAILURE;
    map->vrtx_y = malloc(sizeof(sfVertexArray **) * map->height - 1);
    if (!map->vrtx_y)
        return EXIT_FAILURE;
    for (int i = 0; i < map->height; i++) {
        map->vrtx_x[i] = malloc(sizeof(sfVertexArray *) * (map->width - 1));
        if (!map->vrtx_x[i])
            return EXIT_FAILURE;
    }
    for (int i = 0; i < map->height - 1; i++) {
        map->vrtx_y[i] = malloc(sizeof(sfVertexArray *) * (map->width));
        if (!map->vrtx_y[i])
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int map_vertex_create(map_t *map)
{
    sfVector2f **map_2d = map->map_2d;

    if (map_vertex_malloc(map) == EXIT_FAILURE) {
        my_putstr_error("map_vertex_create: malloc error\n");
        return EXIT_FAILURE;
    }
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width - 1; x++) {
            map->vrtx_x[y][x] = create_line(&map_2d[y][x], &map_2d[y][x + 1]);
        }
    }
    for (int y = 0; y < map->height - 1; y++) {
        for (int x = 0; x < map->width; x++) {
            map->vrtx_y[y][x] = create_line(&map_2d[y][x], &map_2d[y + 1][x]);
        }
    }
    return EXIT_SUCCESS;
}
