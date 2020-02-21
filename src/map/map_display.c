/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_2d_map
*/

#include "my_world.h"

void create_triangle(sfRenderStates *states, sfRenderWindow *window, sfVector2f pos1, sfVector2f pos2, sfVector2f pos3)
{
    sfVertexArray *v_array = sfVertexArray_create();
    sfVector2f p0 = {0, 0};
    sfVector2f p1 = {32, 0};
    sfVector2f p2 = {0, 32};
    sfVertex v1 = {.texCoords = p0, .color = sfWhite};
    sfVertex v2 = {.texCoords = p1, .color = sfWhite};
    sfVertex v3 = {.texCoords = p2, .color = sfWhite};

    v1.position = pos1;
    v2.position = pos2;
    v3.position = pos3;
    sfVertexArray_append(v_array, v1);
    sfVertexArray_append(v_array, v2);
    sfVertexArray_append(v_array, v3);
    sfVertexArray_setPrimitiveType(v_array, sfTrianglesStrip);
    sfRenderWindow_drawVertexArray(window, v_array, states);
    sfVertexArray_destroy(v_array);
}
//sfQuads

int map_display(sfRenderWindow *window, map_t *map)
{
    sfRenderStates states;
    states.shader = NULL;
    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    states.texture = sfTexture_createFromFile("asset/img/grass.jpg", NULL);

    if (map->modified) {
        map_update(map);
        map->modified = sfFalse;
    }
    for (int i = 0; i < map->width - 1; i++)
        for (int j = 0; j < map->height - 1; j++) {
            create_triangle(&states, window, map->map_2d[j][i], map->map_2d[j][i + 1], map->map_2d[j + 1][i]);
            sfRenderWindow_drawVertexArray(window, map->vrtx_x[j][i], NULL);
            sfRenderWindow_drawVertexArray(window, map->vrtx_y[j][i], NULL);
            create_triangle(&states, window, map->map_2d[j + 1][i + 1], map->map_2d[j][i + 1], map->map_2d[j + 1][i]);
            sfRenderWindow_drawVertexArray(window, map->vrtx_x[j + 1][i], NULL);
            sfRenderWindow_drawVertexArray(window, map->vrtx_y[j][i + 1], NULL);
        }
    return EXIT_SUCCESS;
}
