/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Created: 2020-03-06T14:51:13+01:00 | Author: SimonRacaud
*/

#include "my_world.h"

void object_set_size(object_t *obj, int x, int y, int z)
{
    if (!obj)
        return;
    if (x)
        obj->size.x = x;
    if (y)
        obj->size.y = y;
    if (z)
        obj->size.z = z;
    obj->modified = sfTrue;
}
