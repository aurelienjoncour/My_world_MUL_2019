/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_world.h"

int window_run(window_t *w)
{
    text_in_t input;

    text_input_create(&input, "My first text input", 20);

    sfRenderWindow_clear(w->window, sfBlack);
    map_display(w->window, &w->map);
    sfRenderWindow_display(w->window);

    text_input_run(&input);
    text_input_destroy(&input);
    return EXIT_SUCCESS;
}
