/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create 2d vertex array for texture
*/

#include "my_world.h"

extern const char *TEXTURE_PATH[];
extern const int TEXTURE_COUNT;
extern const int TXTR_DIRT;

void map_texture_destroy(map_t *map)
{
    for (int i = 0; i < TEXTURE_COUNT; i++) {
        sfTexture_destroy(map->textures[i]);
    }
    free(map->textures);
    for (int y = 0; y < map->height - 1; y++) {
        free(map->texture_lay[y]);
    }
    free(map->texture_lay);
    map_vertex_texture_destroy(map);
}

static int map_texture_malloc(map_t *map)
{
    map->texture_lay = malloc(sizeof(sfTexture **) * map->height);
    if (!map->texture_lay) {
        my_putstr_error("map_texture_create : malloc error\n");
        return EXIT_FAILURE;
    }
    for (int y = 0; y < map->height; y++) {
        map->texture_lay[y] = malloc(sizeof(sfTexture *) * map->width);
        if (!map->texture_lay[y]) {
            my_putstr_error("map_texture_create : malloc error\n");
            return EXIT_FAILURE;
        }
    }
    map->textures = malloc(sizeof(sfTexture *) * TEXTURE_COUNT);
    if (!map->textures) {
        my_putstr_error("map_texture_create : malloc error\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int map_texture_init(map_t *map)
{
    for (int i = 0; i < TEXTURE_COUNT; i++) {
        map->textures[i] = sfTexture_createFromFile(TEXTURE_PATH[i], NULL);
        if (!map->textures[i]) {
            my_putstr_error("map_texture : load texture\n");
            return EXIT_FAILURE;
        }
    }
    for (int x = 0; x < map->width; x++) {
        for (int y = 0; y < map->height; y++) {
            map->texture_lay[y][x] = map->textures[TXTR_DIRT];
        }
    }
    map->render_state.shader = NULL;
    map->render_state.blendMode = sfBlendAlpha;
    map->render_state.transform = sfTransform_Identity;
    map->render_state.texture = NULL;
    map->rs_black = map->render_state;
    map->rs_black.texture = map->textures[0];
    map->selected_texture = TXTR_DIRT;
    return EXIT_SUCCESS;
}

int map_texture_create(map_t *map)
{
    if (map_texture_malloc(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (map_texture_init(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (map_vertex_texture_create(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
