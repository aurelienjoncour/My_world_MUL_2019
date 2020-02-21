/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** map_generator
*/

#include "my_world.h"

void map_generator(map_t *map)
{
    unsigned int *perm = malloc(sizeof(unsigned int) * 512);

    for (unsigned int i = 0; i < 255; i++)
        perm[i] = i;
    mix_permutation_table(perm);
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            map->map_3d[y][x] = perlin(x, y, 10, perm) * 50;
        }
    }
    free(perm);
    map->modified = sfTrue;
}
