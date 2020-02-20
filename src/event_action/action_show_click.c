/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** IF the user click on the screen -> Display a circle
*/

#include "my_world.h"

void action_show_click(window_t *w)
{
    sfVector2i *click_coord = &w->evt.mouse_click_coord;
    sfVector2i *mouse_coord = &w->evt.mouse_coord;
    sfVector2f mouse_click_coord = {click_coord->x, click_coord->y};
    sfVector2f mouse_coord_float = {mouse_coord->x, mouse_coord->y};
    sfVertex vertex1 = {.position = mouse_coord_float, .color = sfBlue};
    sfVertex vertex2 = {.position = mouse_click_coord, .color = sfBlue};

    sfVertexArray_clear(w->ui.mouse_line);
    sfVertexArray_append(w->ui.mouse_line, vertex1);
    sfVertexArray_append(w->ui.mouse_line, vertex2);
    sfVertexArray_setPrimitiveType(w->ui.mouse_line, sfLinesStrip);
    sfCircleShape_setPosition(w->ui.click_pointer, mouse_click_coord);
    sfRenderWindow_drawVertexArray(w->window, w->ui.mouse_line, NULL);
    sfRenderWindow_drawCircleShape(w->window, w->ui.click_pointer, NULL);
}
