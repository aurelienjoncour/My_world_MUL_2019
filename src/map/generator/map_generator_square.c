/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** map_generator
*/

#include "my_world.h"

static void apply_perlin(map_t *map, int x, int y, unsigned int *perm)
{
    double perlina = perlin(x, y, 15, perm) * 100;
    double perlinb = abs((int)(perlin(x, y, 40, perm) * 120));

    map->map_3d[y][x] = perlina;
    map->map_3d[y][x + 1] = perlina;
    map->map_3d[y + 1][x] = perlina;
    map->map_3d[y + 1][x + 1] = perlina;
    map->map_3d[y][x] += perlinb;
    map->map_3d[y][x + 1] += perlinb;
    map->map_3d[y + 1][x] += perlinb;
    map->map_3d[y + 1][x + 1] += perlinb;
}

void map_generator_square(map_t *map)
{
    unsigned int *perm = malloc(sizeof(unsigned int) * 512);

    for (unsigned int i = 0; i < 256; i++)
        perm[i] = i;
    mix_permutation_table(perm);
    for (int y = 0; y < map->height; y += 2) {
        for (int x = 0; x < map->width; x += 2) {
            apply_perlin(map, x, y, perm);
        }
    }
    free(perm);
    map_texture_set_height(map);
    map->modified = sfTrue;
}
