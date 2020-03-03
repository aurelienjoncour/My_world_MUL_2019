/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** project_iso_point
*/

#include "my_world.h"

sfVector2f obj_project_iso_point(int x, int y, int z, object_t *obj)
{
    sfVector2f point_2d = {0};

    x *= obj->sampling.x;
    y *= obj->sampling.y;
    z *= obj->sampling.z;
    point_2d.x = cos(DEG_TO_RAD(obj->angle.x)) * x -
                cos(DEG_TO_RAD(obj->angle.x)) * y + obj->origin.x;
    point_2d.y = sin(DEG_TO_RAD(obj->angle.y)) * y +
                sin(DEG_TO_RAD(obj->angle.y)) * x - z + obj->origin.y;
    return point_2d;
}
