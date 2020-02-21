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
        if (map->angle.x >= 360)
            map->angle.x -= 360;
        else if (map->angle.x < 0)
            map->angle.x += 360;
        map->modified = sfTrue;
    }
    if (angley != 0) {
        map->angle.y += angley;
        if (map->angle.y >= 360)
            map->angle.y -= 360;
        else if (map->angle.y < 0)
            map->angle.y += 360;
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
    float max_sizex = map->width * map->sampling.x;
    float max_sizey = map->height * map->sampling.y;

    if (map->origin.x <= -max_sizex / 2 && deltax < 0)
        return EXIT_SUCCESS;
    else if (map->origin.x >= (max_sizex * 2.5) && deltax > 0)
        return EXIT_SUCCESS;
    if (map->origin.y <= -max_sizey && deltay < 0)
        return EXIT_SUCCESS;
    else if (map->origin.y >= (max_sizey) && deltay > 0)
        return EXIT_SUCCESS;
    map->origin.x += deltax;
    map->origin.y += deltay;
    if (deltax != 0 || deltay != 0)
        map->modified = sfTrue;
    return EXIT_SUCCESS;
}
