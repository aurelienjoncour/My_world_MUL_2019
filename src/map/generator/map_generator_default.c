/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** map_generator
*/

#include "my_world.h"

void map_generator_default(map_t *map)
{
    unsigned int *perm = malloc(sizeof(unsigned int) * 512);

    for (unsigned int i = 0; i < 256; i++)
        perm[i] = i;
    mix_permutation_table(perm);
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            map->map_3d[y][x] = perlin(x, y, 15, perm) * 100;
            map->map_3d[y][x] += abs((int)(perlin(x, y, 40, perm) * 120));
        }
    }
    free(perm);
    map_texture_set_height(map);
    map->modified = sfTrue;
}
