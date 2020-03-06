/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Created: 2020-03-05T14:51:13+01:00 | Author: SimonRacaud
*/

#include "my_world.h"

int object_on_map_set_coord(object_t *obj, map_t *map, int x, int y)
{
    if (!obj || !map)
        return EXIT_FAILURE;
    if (x < map->width - 1 && x >= 0 && y < map->height - 1 && y >= 0) {
        obj->coord_map.x = x;
        obj->coord_map.y = y;
        object_on_map_refresh(obj, map);
    } else
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int object_on_map_move(object_t *obj, map_t *map, int x, int y)
{
    if (!obj || !map)
        return EXIT_FAILURE;
    obj->coord_map.x += x;
    obj->coord_map.y += y;
    object_on_map_refresh(obj, map);
    return EXIT_SUCCESS;
}

void object_on_map_refresh(object_t *obj, map_t *map)
{
    if (!obj || !map)
        return;
    obj->angle = map->angle;
    if (obj->coord_map.x >= map->width - 1)
        obj->coord_map.x = (map->width - 2);
    else if (obj->coord_map.x < 0)
        obj->coord_map.x = 0;
    if (obj->coord_map.y >= map->height - 1)
        obj->coord_map.y = (map->height - 2);
    else if (obj->coord_map.y < 0)
        obj->coord_map.y = 0;
    obj->origin = map->map_2d[obj->coord_map.y][obj->coord_map.x];
    obj->size.x = map->sampling.x;
    obj->size.y = map->sampling.y;
    obj->size.z = map->sampling.x;
    obj->modified = sfTrue;
}
