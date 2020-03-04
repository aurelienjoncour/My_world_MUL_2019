/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** gui_create
*/

#include "my_world.h"

extern const char *DEFAULT_MAP_NAME;
extern const char *HELP_MENU_TITLE;
extern const char *HELP_MENU_FILEPATH;

static int create_headbar(window_t *w)
{
    int ret = 0;

    ret += button_create(&(w->ui.save), "Save", &button_sizes[SMALL_B],
    &V2F(544, 0));
    ret += button_create(&(w->ui.reset), "Reset", &button_sizes[SMALL_B],
    &V2F(646, 0));
    ret += button_create(&(w->ui.load), "Load", &button_sizes[SMALL_B],
    &V2F(748, 0));
    ret += button_create(&(w->ui.change_map_name), "Edit map name",
    &button_sizes[TALL_B], &V2F(850, 0));
    ret += button_create(&(w->ui.generate_random), "Generate random",
    &button_sizes[TALL_B], &V2F(1080, 0));
    return ret;
}

static int create_viewbar(window_t *w)
{
    int ret = 0;

    ret += button_create(&(w->ui.scale), "Scale", &button_sizes[LMEDIUM_B],
    &V2F(0, 210));
    ret += button_create(&(w->ui.translate), "Translate",
    &button_sizes[LMEDIUM_B], &V2F(0, 260));
    ret += button_create(&(w->ui.rotate), "Rotate", &button_sizes[LMEDIUM_B],
    &V2F(0, 310));
    ret += button_create(&(w->ui.help_menu), "Help Menu",
    &button_sizes[LMEDIUM_B], &V2F(w->width - button_sizes[LMEDIUM_B].x, 0));
    return ret;
}

static int create_toolbar(window_t *w)
{
    int ret = 0;

    ret += button_create(&(w->ui.raise), "Raise", &button_sizes[LMEDIUM_B],
    &V2F(0, 400));
    ret += button_create(&(w->ui.lower), "Lower", &button_sizes[LMEDIUM_B],
    &V2F(0, 450));

    ret += button_create(&(w->ui.level), "Level", &button_sizes[LMEDIUM_B],
    &V2F(0, 500));
    ret += button_create(&(w->ui.texture), "Texture", &button_sizes[LMEDIUM_B],
    &V2F(0, 550));
    return ret;
}

static int create_all_buttons(window_t *w)
{
    int ret = 0;

    ret += create_toolbar(w);
    ret += create_viewbar(w);
    ret += create_headbar(w);
    ret += create_leftbar(w);
    if (ret == 0)
        set_button_config(w);
    return ret;
}

int gui_create(window_t *w)
{
    if (text_input_create(&w->ui.edit_map_name, "New map name", 30,
    DEFAULT_MAP_NAME))
        return EXIT_FAILURE;
    if (text_input_create(&w->ui.load_map_file, "Load: map name", 30,
    ""))
        return EXIT_FAILURE;
    if (texture_menu_create(&w->ui.txr_menu, &w->map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (image_viewer_create(&w->ui.help_menu_viewer, HELP_MENU_FILEPATH,
    HELP_MENU_TITLE))
        return EXIT_FAILURE;
    if (create_all_buttons(w) != 0)
        return EXIT_FAILURE;
    gui_mouse_shapes_create(w);
    if (gui_label_create(w) == EXIT_FAILURE)
        return EXIT_FAILURE;
    slider_create(&w->ui.slider, (sfVector2f){1400, 20}, 300);
    return EXIT_SUCCESS;
}
