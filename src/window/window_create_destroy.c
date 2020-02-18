/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_world.h"

extern const int WIN_HEIGHT;
extern const int WIN_WIDTH;
extern const int WIN_BPP;
extern const int MAP_INIT_HEIGHT;
extern const int MAP_INIT_WIDTH;
extern const unsigned int WIN_FRAMERATE;

int window_create(window_t *w)
{
    sfVideoMode video_mode = {WIN_WIDTH, WIN_HEIGHT, WIN_BPP};

    w->window = sfRenderWindow_create(video_mode, "My World",
    sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(w->window, WIN_FRAMERATE);
    w->mode = ISOMETRIC;
    w->is_fullscreen = sfFalse;
    w->reload_window = sfFalse;
    w->exit_status = EXIT_SUCCESS;
    w->width = WIN_WIDTH;
    w->height = WIN_HEIGHT;
    if (map_create(&w->map, MAP_INIT_HEIGHT, MAP_INIT_WIDTH) == EXIT_FAILURE)
        return EXIT_FAILURE;
    event_init(&w->evt);
    return EXIT_SUCCESS;
}

void window_destroy(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    map_destroy(&w->map);
}
