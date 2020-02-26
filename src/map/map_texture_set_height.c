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

static sfTexture *get_texture(int height, map_t *map)
{
    if (TEXTURE_COUNT < 1)
        return NULL;
    if (TEXTURE_COUNT < 5)
        return map->textures[0];
    if (height < -8)
        return map->textures[TXTR_WATER];
    if (height < 2) {
        return map->textures[TXTR_DIRT];
    } else if (height < 4) {
        return map->textures[TXTR_COBBLESTONE];
    }
    if (height < 6) {
        return map->textures[TXTR_STONE];
    } else
        return map->textures[TXTR_SNOW];
}

int map_texture_set_height(map_t *map)
{
    for (int x = 0; x < map->width - 1; x++) {
        for (int y = 0; y < map->height - 1; y++) {
            map->texture_lay[y][x] = get_texture(map->map_3d[y][x], map);
        }
    }
    return EXIT_SUCCESS;
}
