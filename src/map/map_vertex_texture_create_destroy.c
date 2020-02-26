/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create 2d vertex array for texture
*/

#include "my_world.h"

extern const char *TEXTURE_PATH[];

void map_vertex_texture_destroy(map_t *map)
{
    for (int y = 0; y < map->height - 1; y++) {
        for (int x = 0; x < map->width - 1; x++) {
            sfVertexArray_destroy(map->texture_lay_a[y][x]);
            sfVertexArray_destroy(map->texture_lay_b[y][x]);
        }
        free(map->texture_lay_a[y]);
        free(map->texture_lay_b[y]);
    }
    free(map->texture_lay_a);
    free(map->texture_lay_b);
}

static void create_triangle(sfVertexArray **vertex, sfVector2f *pos)
{
    sfVector2f p0 = {0, 0};
    sfVector2f p1 = {32, 0};
    sfVector2f p2 = {0, 32};
    sfVertex v1 = {.texCoords = p0, .color = sfWhite};
    sfVertex v2 = {.texCoords = p1, .color = sfWhite};
    sfVertex v3 = {.texCoords = p2, .color = sfWhite};

    *vertex = sfVertexArray_create();
    v1.position = pos[0];
    v2.position = pos[1];
    v3.position = pos[2];
    sfVertexArray_append(*vertex, v1);
    sfVertexArray_append(*vertex, v2);
    sfVertexArray_append(*vertex, v3);
    sfVertexArray_setPrimitiveType(*vertex, sfTrianglesStrip);
}

static int map_vertex_texture_malloc(map_t *map, sfVertexArray ****array)
{
    *array = malloc(sizeof(sfVertexArray **) * map->height);
    if (!(*array)) {
        my_putstr_error("map_vertex_texture_create : malloc error\n");
        return EXIT_FAILURE;
    }
    for (int y = 0; y < map->height; y++) {
        (*array)[y] = malloc(sizeof(sfVertexArray *) * map->width);
        if (!(*array)[y]) {
            my_putstr_error("map_vertex_texture_create : malloc error\n");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

static int map_vertex_texture_construct(map_t *map)
{
    sfVector2f position[3];
    const char* TXR_PATH = TEXTURE_PATH[0];

    map->render_state.shader = NULL;
    map->render_state.blendMode = sfBlendAlpha;
    map->render_state.transform = sfTransform_Identity;
    map->render_state.texture = sfTexture_createFromFile(TXR_PATH, NULL);
    map->rs_black = map->render_state;
    map->rs_black.texture = sfTexture_createFromFile(TEXTURE_PATH[1], NULL);
    for (int x = 0; x < map->width - 1; x++) {
        for (int y = 0; y < map->height - 1; y++) {
            position[0] = map->map_2d[y][x];
            position[1] = map->map_2d[y][x + 1];
            position[2] = map->map_2d[y + 1][x];
            create_triangle(&map->texture_lay_a[y][x], position);
            position[0] = map->map_2d[y + 1][x + 1];
            create_triangle(&map->texture_lay_b[y][x], position);
        }
    }
    return EXIT_SUCCESS;
}

int map_vertex_texture_create(map_t *map)
{
    if (map_vertex_texture_malloc(map, &map->texture_lay_a) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (map_vertex_texture_malloc(map, &map->texture_lay_b) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (map_vertex_texture_construct(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (!map->render_state.texture || !map->rs_black.texture) {
        my_putstr_error("map_vertex_texture_create : texture load\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
