/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_world.h"

int run(void)
{
    window_t w;
    sfEvent event;

    if (window_create(&w) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    while (sfRenderWindow_isOpen(w.window)) {
        while (sfRenderWindow_pollEvent(w.window, &event))
            event_manager(&w, &event);
        event_continuous(&w);
        if (window_run(&w) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    window_destroy(&w);
    return w.exit_status;
}

int main(void)
{
    return run();
}
