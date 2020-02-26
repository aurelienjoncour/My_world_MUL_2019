/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_2d_map
*/

#include "my_world.h"

static int get_delta(int **map_3d, int x, int y, int size)
{
    if (x == size - 1 || y == 0)
        return 0;
    if (map_3d[y][x] > map_3d[y][x + 1] &&
        map_3d[y - 1][x] > map_3d[y - 1][x + 1])
        return (map_3d[y][x] + 10) * 0.1;
    if (map_3d[y][x] > map_3d[y][x + 1] &&
        map_3d[y + 1][x] > map_3d[y + 1][x + 1])
        return (map_3d[y][x] + 10) * 0.1;
    return 0;
}

static void map_display_texture(window_t *w, map_t *map, int y, int x)
{
    int delta;

    map->render_state.texture = map->texture_lay[y][x];
    delta = get_delta(map->map_3d, x, y, map->width);
    sfRenderWindow_drawVertexArray(w->window, map->txtr_vrtx_a[y][x],
    &map->render_state);
    for (int i = 0; i < delta; i++)
        sfRenderWindow_drawVertexArray(w->window, map->txtr_vrtx_a[y][x],
        &map->rs_black);
    sfRenderWindow_drawVertexArray(w->window, map->txtr_vrtx_b[y][x],
    &map->render_state);
    for (int i = 0; i < delta; i++)
        sfRenderWindow_drawVertexArray(w->window, map->txtr_vrtx_b[y][x],
        &map->rs_black);
}

static void map_display_last_line(sfRenderWindow *win, map_t *map)
{
    for (int i = 0; i < map->width - 1; i++) {
        sfRenderWindow_drawVertexArray(win, map->vrtx_x[map->height - 1][i],
        NULL);
    }
    for (int i = 0; i < map->height - 1; i++) {
        sfRenderWindow_drawVertexArray(win, map->vrtx_y[i][map->width - 1],
        NULL);
    }
}

int map_display(window_t *w, map_t *map)
{
    sfRenderWindow *win = w->window;

    if (map->modified) {
        map_update(map);
        map->modified = sfFalse;
    }
    for (int x = 0; x < map->width - 1; x++) {
        for (int y = 0; y < map->height - 1; y++) {
            if (w->state.map_display_mode != LINE)
                map_display_texture(w, map, y, x);
            if (w->state.map_display_mode != TXTR) {
                sfRenderWindow_drawVertexArray(win, map->vrtx_x[y][x], NULL);
                sfRenderWindow_drawVertexArray(win, map->vrtx_y[y][x], NULL);
            }
        }
    }
    if (w->state.map_display_mode != TXTR)
        map_display_last_line(win, map);
    return EXIT_SUCCESS;
}
