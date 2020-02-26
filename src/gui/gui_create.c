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
                                            &V2F(640, 0));
    button_set_help_label(&w->ui.save, "Save the map");
    ret += button_create(&(w->ui.reset), "Reset", &button_sizes[SMALL_B],
                                            &V2F(710, 0));
    button_set_help_label(&w->ui.reset, "Reset the map height");
    ret += button_create(&(w->ui.load), "Load", &button_sizes[SMALL_B],
                                            &V2F(780, 0));
    button_set_help_label(&w->ui.load, "Load a map file");
    ret += button_create(&(w->ui.change_map_name), "Edit map name",
                &V2F(200, 35), &V2F(850, 0));
    button_set_help_label(&w->ui.change_map_name, "Edit the map name");
    ret += button_create(&(w->ui.generate_random), "Generate random",
                &V2F(200, 35), &V2F(1060, 0));
    button_set_help_label(&w->ui.generate_random, "Generate a random map");
    return ret;
}

static int create_viewbar(window_t *w)
{
    int ret = 0;

    ret += button_create(&(w->ui.scale), "Scale", &button_sizes[MEDIUM_B],
                                                &V2F(0, 220));
    ret += button_create(&(w->ui.translate), "Translate",
            &button_sizes[MEDIUM_B], &V2F(0, 270));
    ret += button_create(&(w->ui.rotate), "Rotate", &button_sizes[MEDIUM_B],
                                                &V2F(0, 320));
    ret += button_create(&(w->ui.help_menu), "Help Menu",
    &button_sizes[MEDIUM_B], &V2F(w->width - button_sizes[MEDIUM_B].x, 0));
    button_set_help_label(&w->ui.help_menu, "Open help menu");
    return ret;
}

static int create_toolbar(window_t *w)
{
    int ret = 0;

    ret += button_create(&(w->ui.raise), "Raise", &button_sizes[MEDIUM_B],
                                            &V2F(0, 400));
    button_set_ischeckbox(&w->ui.raise, sfTrue);
    button_set_help_label(&w->ui.raise, "Increase points height");
    button_set_status(&w->ui.raise, ACTIVE);
    ret += button_create(&(w->ui.lower), "Lower", &button_sizes[MEDIUM_B],
                                            &V2F(0, 450));
    button_set_ischeckbox(&w->ui.lower, sfTrue);
    button_set_help_label(&w->ui.lower, "Decrease points height");
    ret += button_create(&(w->ui.level), "Level", &button_sizes[MEDIUM_B],
                                            &V2F(0, 500));
    button_set_ischeckbox(&w->ui.level, sfTrue);
    button_set_help_label(&w->ui.level, "Flattens points");
    ret += button_create(&(w->ui.texture), "Texture", &button_sizes[MEDIUM_B],
                                            &V2F(0, 550));
    button_set_ischeckbox(&w->ui.texture, sfTrue);
    button_set_help_label(&w->ui.texture, "Set texture of tiles");
    return ret;
}

static int create_all_buttons(window_t *w)
{
    int ret = 0;

    ret += create_toolbar(w);
    ret += create_viewbar(w);
    ret += create_headbar(w);
    ret += create_leftbar(w);
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
    if (image_viewer_create(&w->ui.help_menu_viewer, HELP_MENU_FILEPATH,
    HELP_MENU_TITLE))
        return EXIT_FAILURE;
    if (create_all_buttons(w) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    gui_mouse_shapes_create(w);
    if (gui_label_create(w) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
