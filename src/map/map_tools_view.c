/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_tools
*/

#include "my_world.h"

int map_set_anglex(map_t *map, float anglex)
{
    map->angle.x = anglex;
    map->modified = sfTrue;
    return EXIT_SUCCESS;
}

int map_set_angley(map_t *map, float angley)
{
    map->angle.y = angley;
    map->modified = sfTrue;
    return EXIT_SUCCESS;
}

int map_rotate(map_t *map, float anglex, float angley)
{
    if (anglex != 0) {
        map->angle.x += anglex;
        map->modified = sfTrue;
    }
    if (angley != 0) {
        map->angle.y += angley;
        map->modified = sfTrue;
    }
    return EXIT_SUCCESS;
}

int map_scale(map_t *map, float scale)
{
    if ((map->sampling.x != 0) || (map->sampling.x == 0 && scale > 0))
        map->sampling.x += scale;
    if ((map->sampling.y != 0) || (map->sampling.y == 0 && scale > 0))
        map->sampling.y += scale;
    if ((map->sampling.z != 0) || (map->sampling.z == 0 && scale > 0))
        map->sampling.z += scale * 10 / 64;
    map->modified = sfTrue;
    return EXIT_SUCCESS;
}

int map_translate(map_t *map, float deltax, float deltay)
{
    map->origin.x += deltax;
    map->origin.y += deltay;
    if (deltax != 0 || deltay != 0)
        map->modified = sfTrue;
    return EXIT_SUCCESS;
}
