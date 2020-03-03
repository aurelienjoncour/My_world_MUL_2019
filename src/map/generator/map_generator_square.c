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

    for (int a = 0; a < 2; a++) {
        if (y + a == map->height)
            break;
        for (int b = 0; b < 2; b++) {
            if (x + b == map->width)
                break;
            map->map_3d[y + a][x + b] = perlina;
            map->map_3d[y + a][x + b] += perlinb;
        }
    }
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


static void apply_perlin2(map_t *map, int x, int y, unsigned int *perm)
{
    double perlina = perlin(x, y, 15, perm) * 100;
    double perlinb = abs((int)(perlin(x, y, 40, perm) * 120));

    for (int a = 0; a < 3; a++) {
        if (y + a == map->height)
            break;
        for (int b = 0; b < 3; b++) {
            if (x + b == map->width)
                break;
            map->map_3d[y + a][x + b] = perlina;
            map->map_3d[y + a][x + b] += perlinb;
        }
    }
}

void map_generator_square_two(map_t *map)
{
    unsigned int *perm = malloc(sizeof(unsigned int) * 512);

    for (unsigned int i = 0; i < 256; i++)
        perm[i] = i;
    mix_permutation_table(perm);
    for (int y = 0; y < map->height; y += 3) {
        for (int x = 0; x < map->width; x += 3) {
            apply_perlin2(map, x, y, perm);
        }
    }
    free(perm);
    map_texture_set_height(map);
    map->modified = sfTrue;
}
