/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_2d_map
*/

#include "my_world.h"

int map_display(window_t *w, map_t *map)
{
    sfRenderWindow *window = w->window;

    if (map->modified) {
        map_update(map);
        map->modified = sfFalse;
    }
    for (int i = 0; i < map->width - 1; i++)
        for (int j = 0; j < map->height - 1; j++) {
            if (w->state.map_show_texture)
                sfRenderWindow_drawVertexArray(window,
                map->texture_lay_a[j][i], &map->render_state);
            sfRenderWindow_drawVertexArray(window, map->vrtx_x[j][i], NULL);
            sfRenderWindow_drawVertexArray(window, map->vrtx_y[j][i], NULL);
            if (w->state.map_show_texture)
                sfRenderWindow_drawVertexArray(window,
                map->texture_lay_b[j][i], &map->render_state);
            sfRenderWindow_drawVertexArray(window, map->vrtx_x[j + 1][i], NULL);
            sfRenderWindow_drawVertexArray(window, map->vrtx_y[j][i + 1], NULL);
        }
    return EXIT_SUCCESS;
}
