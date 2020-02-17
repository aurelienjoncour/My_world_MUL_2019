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
    map_create(&w.map, 6, 6);
    while (sfRenderWindow_isOpen(w.window)) {
        while (sfRenderWindow_pollEvent(w.window, &event))
            manage_events(&w, &event);
        map_display(w.window, &w.map);
        sfRenderWindow_display(w.window);
    }
    window_destroy(&w);
    return w.exit_status;
}

int main(void)
{
    return run();
}
