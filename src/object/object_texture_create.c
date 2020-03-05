/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** 2020-03-05T14:33:04+01:00 : simon
*/

#include "my_world.h"

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

static void object_vertex_texture_construct_sub(object_t *obj)
{
    sfVector2f position[3];

    position[0] = obj->mtx_2d[1][0][0];
    position[1] = obj->mtx_2d[1][0][1];
    position[2] = obj->mtx_2d[1][1][0];
    create_triangle(&obj->vrtx_txr_a[0], position);
    position[0] = obj->mtx_2d[1][1][1];
    create_triangle(&obj->vrtx_txr_b[0], position);
    position[0] = obj->mtx_2d[0][0][1];
    position[1] = obj->mtx_2d[1][0][1];
    position[2] = obj->mtx_2d[0][1][1];
    create_triangle(&obj->vrtx_txr_a[1], position);
    position[0] = obj->mtx_2d[1][1][1];
    create_triangle(&obj->vrtx_txr_b[1], position);
}

static int object_vertex_texture_construct(object_t *obj)
{
    sfVector2f position[3];

    object_vertex_texture_construct_sub(obj);
    position[0] = obj->mtx_2d[0][1][0];
    position[1] = obj->mtx_2d[1][1][0];
    position[2] = obj->mtx_2d[0][1][1];
    create_triangle(&obj->vrtx_txr_a[2], position);
    position[0] = obj->mtx_2d[1][1][1];
    create_triangle(&obj->vrtx_txr_b[2], position);
    return EXIT_SUCCESS;
}

int object_init_texture(object_t *obj, const char **img_path)
{
    obj->render_state.shader = NULL;
    obj->render_state.blendMode = sfBlendAlpha;
    obj->render_state.transform = sfTransform_Identity;
    obj->render_state.texture = NULL;
    for (int i = 0; i < 3; i++) {
        obj->textures[i] = sfTexture_createFromFile(img_path[i], NULL);
        if (!obj->textures[i])
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int object_texture_create(object_t *obj, const char **img_path)
{
    if (object_init_texture(obj, img_path) == EXIT_FAILURE)
        return EXIT_FAILURE;
    object_vertex_texture_construct(obj);
    return EXIT_SUCCESS;
}
