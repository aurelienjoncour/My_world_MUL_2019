/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_world.h"

int window_run(window_t *w)
{
    w->timer += sfTime_asMilliseconds(sfClock_getElapsedTime(w->clock));
    sfClock_restart(w->clock);
    sfRenderWindow_clear(w->window, sfBlack);
    action_manager(w);
    map_display(w, &w->map);
    gui_display(w);
    if (w->timer >= w->ms_loop) {
        while (w->timer >= w->ms_loop)
            w->timer -= w->ms_loop;
        gui_panel_update(w);
    }
    sfRenderWindow_display(w->window);
    return EXIT_SUCCESS;
}
