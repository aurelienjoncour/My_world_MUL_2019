/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit map height
*/

#include "my_world.h"

int area_mode(map_t *map, sfVector2f mouse)
{
    int exit_status = 0;
    int ret = 0;

    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            ret = map_edit_height_edit_point(map, &mouse, y, x);
            exit_status = (ret == 1) ? (1) : exit_status;
        }
    }
    return exit_status;
}

static int raise_tiles(map_t *map, int i, int j)
{
    map->map_3d[j][i]++;
    map->map_3d[j][i - 1]++;
    map->map_3d[j - 1][i]++;
    map->map_3d[j - 1][i - 1]++;
    map->modified = sfTrue;
    return 1;
}

static int corner_mode(map_t *map, sfVector2f mouse)
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
    map->map_3d[save.y][save.x]++;
    map->modified = true;
    return 1;
}

static int tiles_mode(map_t *map, sfVector2f mouse)
{
    for (int j = map->height - 1; j > 0; j--)
        for (int i = map->width - 1; i > 0; i--) {
            if (point_is_on_triangle(map->map_2d[j][i], map->map_2d[j][i - 1],
                       map->map_2d[j - 1][i], mouse))
                    return raise_tiles(map, i, j);
                if (point_is_on_triangle(map->map_2d[j - 1][i - 1],
                    map->map_2d[j][i - 1], map->map_2d[j - 1][i], mouse))
                    return raise_tiles(map, i, j);
        }
    return 0;
}

int map_edit_height(map_t *map, state_t *state, float x, float y)
{
    sfVector2f mouse = {x, y};

    if (state->select_mode == TILE)
        return tiles_mode(map, mouse);
    if (state->select_mode == CORNER)
        return corner_mode(map, mouse);
    if (state->select_mode == AREA)
        return area_mode(map, mouse);
    return 0;
}
