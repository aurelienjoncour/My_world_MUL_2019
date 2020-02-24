/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

int area_mode(map_t *map, sfVector2f mouse, int coefficient)
{
    int exit_status = 0;
    int ret = 0;
    sfVector2i indice = {0};

    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            indice.x = x;
            indice.y = y;
            ret = map_edit_height_edit_point(map, &mouse, indice, coefficient);
            exit_status = (ret == 1) ? (1) : exit_status;
        }
    }
    return exit_status;
}

static int raise_tiles(map_t *map, int i, int j, int coefficient)
{
    map->map_3d[j][i] += coefficient;
    map->map_3d[j][i - 1] += coefficient;
    map->map_3d[j - 1][i] += coefficient;
    map->map_3d[j - 1][i - 1] += coefficient;
    map->modified = sfTrue;
    return 1;
}

static int corner_mode(map_t *map, sfVector2f mouse, int coefficient)
{
    float lenght = point_length(mouse, map->map_2d[0][0]);
    sfVector2i save = {0};

    for (int i = map->height - 1; i >= 0; i--) {
        for (int j = map->width - 1; j >= 0; j--) {
            if (point_length(mouse, map->map_2d[i][j]) < lenght) {
                lenght = point_length(mouse, map->map_2d[i][j]);
                save.x = j;
                save.y = i;
            }
        }
    }
    map->map_3d[save.y][save.x] += coefficient;
    map->modified = true;
    return 1;
}

static int tiles_mode(map_t *map, sfVector2f mouse, int coefficient)
{
    for (int j = map->height - 1; j > 0; j--)
        for (int i = map->width - 1; i > 0; i--) {
            if (point_is_on_triangle(map->map_2d[j][i], map->map_2d[j][i - 1],
                       map->map_2d[j - 1][i], mouse))
                    return raise_tiles(map, i, j, coefficient);
                if (point_is_on_triangle(map->map_2d[j - 1][i - 1],
                    map->map_2d[j][i - 1], map->map_2d[j - 1][i], mouse))
                    return raise_tiles(map, i, j, coefficient);
        }
    return 0;
}

int map_edit_height(window_t *w, float x, float y)
{
    sfVector2f mouse = {x, y};
    int coefficient = 1;

    if (w->state.tool == RAISE)
        coefficient = 1;
    if (w->state.tool == LOWER)
        coefficient = -1;
    if (w->state.select_mode == TILE)
        return tiles_mode(&w->map, mouse, coefficient);
    if (w->state.select_mode == CORNER)
        return corner_mode(&w->map, mouse, coefficient);
    if (w->state.select_mode == AREA)
        return area_mode(&w->map, mouse, coefficient);
    return 0;
}
