/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_world.h"

int run(int ac, char **av)
{
    window_t w;
    sfEvent event;

    if (window_create(&w) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (ac == 2)
        load_map(av[1], &w.map);
    gui_create(&w);
    while (sfRenderWindow_isOpen(w.window)) {
        while (sfRenderWindow_pollEvent(w.window, &event))
            event_manager(&w, &event);
        if (window_run(&w) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    window_destroy(&w);
    return w.exit_status;
}

int main(int ac, char **av)
{
    return run(ac, av);
}
