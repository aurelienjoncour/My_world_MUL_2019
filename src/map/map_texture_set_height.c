/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create 2d vertex array for texture
*/

#include "my_world.h"

extern const char *TEXTURE_PATH[];
extern const int TEXTURE_COUNT;
extern const int TXTR_WATER;
extern const int TXTR_DIRT;
extern const int TXTR_COBBLESTONE;
extern const int TXTR_STONE;
extern const int TXTR_SNOW;

static int texture(int height)
{
    if (TEXTURE_COUNT < 1)
        return 0;
    if (TEXTURE_COUNT < 5)
        return 0;
    if (height < -8)
        return TXTR_WATER;
    if (height < 2) {
        return TXTR_DIRT;
    } else if (height < 4) {
        return TXTR_COBBLESTONE;
    }
    if (height < 6) {
        return TXTR_STONE;
    } else
        return TXTR_SNOW;
}

int map_texture_set_height(map_t *map)
{
    for (int x = 0; x < map->width - 1; x++) {
        for (int y = 0; y < map->height - 1; y++)
            map->texture_const[y][x] = texture(map->map_3d[y][x]);
    }
    return EXIT_SUCCESS;
}
