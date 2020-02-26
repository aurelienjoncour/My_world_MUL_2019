/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create_leftbar
*/

#include "my_world.h"

static int create_resize_button(window_t *w)
{
    int ret = 0;

    ret += button_create(&(w->ui.map_x_m), "x -", &button_sizes[SQUARE_B],
            &V2F(0, 650));
    button_set_help_label(&w->ui.map_x_m, "Decrease map width");
    ret += button_create(&(w->ui.map_x_p), "x +", &button_sizes[SQUARE_B],
            &V2F(65, 650));
    button_set_help_label(&w->ui.map_x_p, "Increase map width");
    ret += button_create(&(w->ui.map_y_m), "y -", &button_sizes[SQUARE_B],
            &V2F(0, 720));
    button_set_help_label(&w->ui.map_y_m, "Decrease map height");
    ret += button_create(&(w->ui.map_y_p), "y +", &button_sizes[SQUARE_B],
            &V2F(65, 720));
    button_set_help_label(&w->ui.map_y_p, "Increase map height");
    return ret;
}

int create_leftbar(window_t *w)
{
    int ret = 0;

    ret += create_resize_button(w);
    ret += button_create(&(w->ui.menu_texture), "Menu Texture",
            &button_sizes[LARGE_B], &V2F(0, 850));
    button_set_help_label(&w->ui.menu_texture, "Open texture menu");
    ret += button_create(&(w->ui.select_mode), "Select Mode",
            &button_sizes[LARGE_B], &V2F(0, 900));
    button_set_help_label(&w->ui.select_mode, "Change select mode");
    return ret;
}