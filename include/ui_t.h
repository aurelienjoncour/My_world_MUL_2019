/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** ui_t
*/

#ifndef UI_T_H_
#define UI_T_H_

#include "button.h"

typedef struct user_interface {
    sfCircleShape *click_pointer;
    sfVertexArray *mouse_line;
    button_t save;
    button_t reset;
    button_t load;
    button_t generate_random;
    button_t help_menu;
    button_t scale;
    button_t translate;
    button_t rotate;
    button_t raise;
    button_t lower;
    button_t level;
    button_t texture;
    button_t map_y_p;
    button_t map_y_m;
    button_t map_x_m;
    button_t map_x_p;
    button_t menu_texture;
    button_t select_mode;
} ui_t;

#endif
