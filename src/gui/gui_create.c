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

static void create_headbar(window_t *w)
{
    button_create(&(w->ui.save), "Save", &button_sizes[SMALL_B],
                                            &(sfVector2f){640, 0});
    button_create(&(w->ui.reset), "Reset", &button_sizes[SMALL_B],
                                            &(sfVector2f){710, 0});
    button_create(&(w->ui.load), "Load", &button_sizes[SMALL_B],
                                            &(sfVector2f){780, 0});
    button_create(&(w->ui.change_map_name), "Edit map name",
                &(sfVector2f){200, 35}, &(sfVector2f){850, 0});
    button_create(&(w->ui.generate_random), "Generate random",
                &(sfVector2f){200, 35}, &(sfVector2f){1060, 0});
}

static void create_viewbar(window_t *w)
{
    button_create(&(w->ui.scale), "Scale", &button_sizes[MEDIUM_B],
                                                &(sfVector2f){0, 220});
    button_create(&(w->ui.translate), "Translate", &button_sizes[MEDIUM_B],
                                                &(sfVector2f){0, 270});
    button_create(&(w->ui.rotate), "Rotate", &button_sizes[MEDIUM_B],
                                                &(sfVector2f){0, 320});
}

static void create_toolbar(window_t *w)
{
    button_create(&(w->ui.raise), "Raise", &button_sizes[MEDIUM_B],
                                            &(sfVector2f){0, 4000});
    button_create(&(w->ui.lower), "Lower", &button_sizes[MEDIUM_B],
                                            &(sfVector2f){0, 450});
    button_create(&(w->ui.level), "Level", &button_sizes[MEDIUM_B],
                                            &(sfVector2f){0, 500});
    button_create(&(w->ui.texture), "Texture", &button_sizes[MEDIUM_B],
                                            &(sfVector2f){0, 550});
}

static void create_other(window_t *w)
{
    button_create(&(w->ui.help_menu), "Help Menu", &button_sizes[MEDIUM_B],
                &(sfVector2f){w->width - button_sizes[MEDIUM_B].x, 0});
    button_create(&(w->ui.map_x_m), "x -", &button_sizes[SQUARE_B],
                                                &(sfVector2f){0, 650});
    button_create(&(w->ui.map_x_p), "x +", &button_sizes[SQUARE_B],
                                                &(sfVector2f){65, 650});
    button_create(&(w->ui.map_y_m), "y -", &button_sizes[SQUARE_B],
                                                &(sfVector2f){0, 720});
    button_create(&(w->ui.map_y_p), "y +", &button_sizes[SQUARE_B],
                                                &(sfVector2f){65, 720});
    button_create(&(w->ui.menu_texture), "Menu Texture", &button_sizes[LARGE_B],
                                                &(sfVector2f){0, 850});
    button_create(&(w->ui.select_mode), "Select Mode", &button_sizes[LARGE_B],
                                                &(sfVector2f){0, 900});
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
    create_toolbar(w);
    create_viewbar(w);
    create_headbar(w);
    create_other(w);
    gui_mouse_shapes_create(w);
    return EXIT_SUCCESS;
}
