/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** gui_destroy
*/

#include "my_world.h"

void gui_destroy_button(ui_t *ui)
{
    button_destroy(&ui->save);
    button_destroy(&ui->reset);
    button_destroy(&ui->load);
    button_destroy(&ui->change_map_name);
    button_destroy(&ui->generate_random);
    button_destroy(&ui->help_menu);
    button_destroy(&ui->scale);
    button_destroy(&ui->translate);
    button_destroy(&ui->rotate);
    button_destroy(&ui->raise);
    button_destroy(&ui->lower);
    button_destroy(&ui->level);
    button_destroy(&ui->texture);
    button_destroy(&ui->map_x_m);
    button_destroy(&ui->map_x_p);
    button_destroy(&ui->map_y_m);
    button_destroy(&ui->map_y_p);
    button_destroy(&ui->menu_texture);
    button_destroy(&ui->select_mode);
}

int gui_destroy(ui_t *ui)
{
    gui_destroy_button(ui);
    gui_mouse_shapes_destroy(ui);
    text_input_destroy(&ui->edit_map_name);
    text_input_destroy(&ui->load_map_file);
    image_viewer_destroy(&ui->help_menu_viewer);
    return 0;
}
