/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** gui_create shapes
*/

#include "my_world.h"

extern const float CIRCLE_CLICK_RADIUS;

int gui_mouse_shapes_create(window_t *w)
{
    sfVector2f c_origin = {CIRCLE_CLICK_RADIUS, CIRCLE_CLICK_RADIUS};
    w->ui.click_pointer = sfCircleShape_create();
    w->ui.mouse_line = sfVertexArray_create();
    if (!w->ui.click_pointer || !w->ui.mouse_line) {
        my_putstr_error("gui_mouse_shapes_create : error object create\n");
        return EXIT_FAILURE;
    }
    sfCircleShape_setFillColor(w->ui.click_pointer, sfBlue);
    sfCircleShape_setRadius(w->ui.click_pointer, CIRCLE_CLICK_RADIUS);
    sfCircleShape_setOrigin(w->ui.click_pointer, c_origin);
    return EXIT_SUCCESS;
}

void gui_mouse_shapes_destroy(ui_t *ui)
{
    sfVertexArray_destroy(ui->mouse_line);
    sfCircleShape_destroy(ui->click_pointer);
}
