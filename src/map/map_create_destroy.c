/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_t
*/

#include "my_world.h"

extern const sfVector3f MAP_INIT_SAMP;
extern const sfVector2f MAP_INIT_ANGL;
extern const sfVector2f MAP_INIT_ORIG;
extern const char *DEFAULT_MAP_NAME;

void map_destroy(map_t *map)
{
    destroy_2d_map(map->map_2d, map->height);
    destroy_3d_map(map->map_3d, map->height);
    map_vertex_destroy(map);
    free(map->map_name);
    map_texture_destroy(map);
    for (int i = 0; i < map->height; i++)
        free(map->texture_const[i]);
    free(map->texture_const);
}

static void map_init(map_t *map, int height, int width)
{
    map->map_name = my_strdup(DEFAULT_MAP_NAME);
    map->map_3d = NULL;
    map->map_2d = NULL;
    map->vrtx_x = NULL;
    map->vrtx_y = NULL;
    map->sampling = MAP_INIT_SAMP;
    map->angle = MAP_INIT_ANGL;
    map->origin = MAP_INIT_ORIG;
    map->height = height;
    map->width = width;
    map->modified = sfFalse;
}

static void map_texture_const_create(map_t *map)
{
    map->texture_const = malloc(sizeof(int *) * map->height);
    for (int i = 0; i < map->height; i++) {
        map->texture_const[i] = malloc(sizeof(int) * map->width);
        for (int j = 0; j < map->width; j++)
            map->texture_const[i][j] = 2;
    }

}

int map_create(map_t *map, int height, int width)
{
    map_init(map, height, width);
    map_texture_const_create(map);
    map->map_3d = create_3d_map(height, width);
    if (!map->map_3d)
        return EXIT_FAILURE;
    if (create_2d_map(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (map_vertex_create(map) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (map_texture_create(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
