/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** map_generator
*/

#include "my_world.h"

int map_anim_create(map_t *map)
{
    map->map_3d_anim_sens = create_3d_map(map->height, map->width);
    if (!map->map_3d_anim_sens) {
        my_putstr_error("map anim create : error\n");
        return EXIT_FAILURE;
    }
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            map->map_3d_anim_sens[y][x] = 1;
        }
    }
    int height = 0;
    int sens = 1;
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            map->map_3d[y][x] = height;
        }
        height += (sens * 2);
        if (height >= 20 || height == 0)
        sens = -sens;
    }
    return EXIT_SUCCESS;
}

void map_anim_destroy(map_t *map)
{
    destroy_3d_map(map->map_3d_anim_sens, map->height);
}

void map_anim_water(map_t *map)
{
    const int MAX_HEIGHT = 22;

    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            map->map_3d[y][x] += map->map_3d_anim_sens[y][x];
            if (map->map_3d[y][x] >= MAX_HEIGHT || map->map_3d[y][x] <= 0)
                map->map_3d_anim_sens[y][x] = (-map->map_3d_anim_sens[y][x]);
        }
    }
    map->modified = sfTrue;
}
