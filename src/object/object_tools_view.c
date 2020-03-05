/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** object tools view
*/

#include "my_world.h"

int object_rotate(object_t *obj, float anglex, float angley)
{
    float max_x = 90;
    float max_y = 180;

    if (anglex != 0) {
        obj->angle.x += anglex;
        if (obj->angle.x >= max_x)
            obj->angle.x -= max_x;
        else if (obj->angle.x < 0)
            obj->angle.x += max_x;
        obj->modified = sfTrue;
    }
    if (angley != 0) {
        obj->angle.y += angley;
        if (obj->angle.y >= max_y)
            obj->angle.y -= max_y;
        else if (obj->angle.y < 0)
            obj->angle.y += max_y;
        obj->modified = sfTrue;
    }
    return EXIT_SUCCESS;
}

int object_translate(object_t *obj, float deltax, float deltay, window_t *w)
{
    float max_sizex = obj->width * obj->size.x;
    float max_sizey = obj->width * obj->size.y;

    if (obj->origin.x <= -max_sizex && deltax < 0)
        return EXIT_SUCCESS;
    else if (obj->origin.x >= w->width + max_sizex && deltax > 0)
        return EXIT_SUCCESS;
    if (obj->origin.y <= -max_sizey && deltay < 0)
        return EXIT_SUCCESS;
    else if (obj->origin.y >= w->height && deltay > 0)
        return EXIT_SUCCESS;
    obj->origin.x += deltax;
    obj->origin.y += deltay;
    if (deltax != 0 || deltay != 0)
        obj->modified = sfTrue;
    return EXIT_SUCCESS;
}
