/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** gui
*/

#ifndef GUI_H_
#define GUI_H_

#include "my_world.h"

int gui_display(window_t *w);
int gui_create(window_t *w);

enum BUTTON_SIZES {
    SMALL_B = 0,
    MEDIUM_B = 1,
    LARGE_B = 2,
    SQUARE_B = 3,
};

extern const sfVector2f button_sizes[];

int gui_mouse_shapes_create(window_t *w);
void gui_mouse_shapes_destroy(ui_t *ui);
int gui_label_create(window_t *w);
int gui_destroy(ui_t *ui);

int gui_panel_update(window_t *w);

#endif /* !GUI_H_ */
