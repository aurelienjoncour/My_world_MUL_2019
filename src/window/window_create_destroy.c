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
extern const sfInt32 MS_UPDATE_PANEL;

static int window_create_clock(window_t *w)
{
    w->timer = 0;
    w->ms_loop = MS_UPDATE_PANEL;
    w->clock = sfClock_create();
    if (!w->clock)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static void window_create_init(window_t *w)
{
    w->mode = ISOMETRIC;
    w->is_fullscreen = sfFalse;
    w->reload_window = sfFalse;
    w->exit_status = EXIT_SUCCESS;
    w->width = WIN_WIDTH;
    w->height = WIN_HEIGHT;
}

int window_create(window_t *w)
{
    sfVideoMode video_mode = {WIN_WIDTH, WIN_HEIGHT, WIN_BPP};

    window_create_init(w);
    w->window = sfRenderWindow_create(video_mode, "My World",
    sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w->window, WIN_FRAMERATE);
    sfRenderWindow_setPosition(w->window, (sfVector2i){0, 0});
    if (map_create(&w->map, MAP_INIT_HEIGHT, MAP_INIT_WIDTH) == EXIT_FAILURE)
        return EXIT_FAILURE;
    event_init(&w->evt);
    soft_state_init(&w->state);
    if (window_create_clock(w) == EXIT_FAILURE)
        return EXIT_FAILURE;
    else if (sound_manager_create(&w->sm) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void window_destroy(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    map_destroy(&w->map);
    gui_destroy(&w->ui);
    sfClock_destroy(w->clock);
    sound_manager_destroy(&w->sm);
}
