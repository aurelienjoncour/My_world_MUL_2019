/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_world.h"

extern const int WIN_BPP;
extern const unsigned int WIN_FRAMERATE;

int window_reload(window_t *w)
{
    sfVideoMode video_mode = {w->width, w->height, WIN_BPP};

    sfRenderWindow_destroy(w->window);
    w->window = sfRenderWindow_create(video_mode, "My World",
    sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(w->window, WIN_FRAMERATE);
    return EXIT_SUCCESS;
}
