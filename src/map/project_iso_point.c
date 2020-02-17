/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** project_iso_point
*/

#include "my_world.h"

sfVector2f project_iso_point(int x, int y, int z, sfVector2f translation)
{
    sfVector2f point_2d = {0};
    int angle_x = 45;
    int angle_y = 35;

    x *= SAMPLING;
    y *= SAMPLING;
    z *= 10;
    point_2d.x = cos(DEG_TO_RAD(45)) * x - cos(DEG_TO_RAD(45)) * y
                + translation.x;
    point_2d.y = sin(DEG_TO_RAD(35)) * y + sin(DEG_TO_RAD(35)) * x - z
                + translation.y;
    return point_2d;
}