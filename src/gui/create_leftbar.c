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
    ret += button_create(&(w->ui.map_x_p), "x +", &button_sizes[SQUARE_B],
            &V2F(65, 650));
    ret += button_create(&(w->ui.map_y_m), "y -", &button_sizes[SQUARE_B],
            &V2F(0, 715));
    ret += button_create(&(w->ui.map_y_p), "y +", &button_sizes[SQUARE_B],
            &V2F(65, 715));
    return ret;
}

static void set_button_help_label(window_t *w)
{
    button_set_help_label(&w->ui.map_x_m, "Decrease map width");
    button_set_help_label(&w->ui.map_x_p, "Increase map width");
    button_set_help_label(&w->ui.map_y_m, "Decrease map height");
    button_set_help_label(&w->ui.map_y_p, "Increase map height");
    button_set_help_label(&w->ui.menu_texture, "Open texture menu");
    button_set_help_label(&w->ui.select_mode, "Change select mode");
    button_set_help_label(&w->ui.save, "Save the map");
    button_set_help_label(&w->ui.reset, "Reset the map height");
    button_set_help_label(&w->ui.load, "Load a map file");
    button_set_help_label(&w->ui.change_map_name, "Edit the map name");
    button_set_help_label(&w->ui.generate_random, "Generate a random map");
    button_set_help_label(&w->ui.help_menu, "Open help menu");
    button_set_help_label(&w->ui.raise, "Increase points height");
    button_set_help_label(&w->ui.lower, "Decrease points height");
    button_set_help_label(&w->ui.texture, "Set texture of tiles");
    button_set_help_label(&w->ui.level, "Flattens points");
    button_set_help_label(&w->ui.translate, "Reset origin");
    button_set_help_label(&w->ui.rotate, "Reset angle");
    button_set_help_label(&w->ui.scale, "Reset scale");
}

void set_button_config(window_t *w)
{
    button_set_ischeckbox(&w->ui.raise, sfTrue);
    button_set_status(&w->ui.raise, ACTIVE);
    button_set_ischeckbox(&w->ui.lower, sfTrue);
    button_set_ischeckbox(&w->ui.level, sfTrue);
    button_set_ischeckbox(&w->ui.texture, sfTrue);
    set_button_help_label(w);
}

int create_leftbar(window_t *w)
{
    int ret = 0;

    ret += create_resize_button(w);
    ret += button_create(&(w->ui.menu_texture), "Menu Texture",
            &button_sizes[LMEDIUM_B], &V2F(0, 820));
    ret += button_create(&(w->ui.select_mode), "Select Mode",
            &button_sizes[LMEDIUM_B], &V2F(0, 870));
    return ret;
}
