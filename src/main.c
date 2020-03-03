/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_world.h"

extern const char *MAP_EXTENSION;

static int main_loop(window_t *w)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event);
        if (window_run(w) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (w->reload_window) {
        w->reload_window = sfFalse;
        window_reload(w);
        main_loop(w);
    }
    return EXIT_SUCCESS;
}

int run(int ac, char **av)
{
    window_t w;

    if (window_create(&w) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (ac == 2 && load_from_argv(av[1], &w) == EXIT_ERROR) {
        window_destroy(&w);
        return EXIT_FAILURE;
    }
    if (map_create(&w.map_water, w.map.height, w.map.width))
        return EXIT_FAILURE;
    sound_manager_play(&w.sm, SOUND_START);
    main_loop(&w);
    auto_save(&w.map);
    window_destroy(&w);
    return w.exit_status;
}

int main(int ac, char **av)
{
    if (ac != 1 && !schr_extension(av[1], MAP_EXTENSION)) {
        my_putstr("Bad file extension: .world only\n");
        return EXIT_ERROR;
    }
    return run(ac, av);
}
