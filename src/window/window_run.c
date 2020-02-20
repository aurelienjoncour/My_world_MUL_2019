/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_world.h"

int window_run(window_t *w)
{
    sfRenderWindow_clear(w->window, sfBlack);
    map_display(w->window, &w->map);
    gui_display(w);
    event_continuous(w);
    sfRenderWindow_display(w->window);
    return EXIT_SUCCESS;
}
