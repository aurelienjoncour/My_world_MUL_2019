/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** project_iso_point
*/

#include "my_world.h"

sfVector2f project_iso_point(int x, int y, int z, map_t *map)
{
    sfVector2f point_2d = {0};

    x *= map->sampling.x;
    y *= map->sampling.y;
    z *= map->sampling.z;
    point_2d.x = cos(DEG_TO_RAD(map->angle.x)) * x -
                cos(DEG_TO_RAD(map->angle.x)) * y + map->origin.x;
    point_2d.y = sin(DEG_TO_RAD(map->angle.y)) * y +
                sin(DEG_TO_RAD(map->angle.y)) * x - z + map->origin.y;
    return point_2d;
}