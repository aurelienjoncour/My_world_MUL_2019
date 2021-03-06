/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** gui_display
*/

#include "my_world.h"

static void gui_display_button(window_t *w)
{
    button_display(&(w->ui.save), w->window);
    button_display(&(w->ui.reset), w->window);
    button_display(&(w->ui.load), w->window);
    button_display(&(w->ui.generate_random), w->window);
    button_display(&(w->ui.change_map_name), w->window);
    button_display(&(w->ui.help_menu), w->window);
    button_display(&(w->ui.select_mode), w->window);
    button_display(&(w->ui.menu_texture), w->window);
    button_display(&(w->ui.map_y_p), w->window);
    button_display(&(w->ui.map_y_m), w->window);
    button_display(&(w->ui.map_x_p), w->window);
    button_display(&(w->ui.map_x_m), w->window);
    button_display(&(w->ui.texture), w->window);
    button_display(&(w->ui.level), w->window);
    button_display(&(w->ui.lower), w->window);
    button_display(&(w->ui.raise), w->window);
    button_display(&(w->ui.rotate), w->window);
    button_display(&(w->ui.translate), w->window);
    button_display(&(w->ui.scale), w->window);
}

static void gui_display_text(ui_t *ui, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, ui->txt_map_name, NULL);
    sfRenderWindow_drawText(window, ui->txt_select_mode, NULL);
    sfRenderWindow_drawText(window, ui->txt_angle, NULL);
    sfRenderWindow_drawText(window, ui->txt_origin, NULL);
    sfRenderWindow_drawText(window, ui->txt_scale, NULL);
    sfRenderWindow_drawText(window, ui->txt_size, NULL);
}

int gui_display(window_t *w)
{
    gui_display_button(w);
    gui_display_text(&w->ui, w->window);
    slider_display(&w->ui.slider, w->window);
    return EXIT_SUCCESS;
}
