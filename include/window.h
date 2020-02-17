/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_t
*/

#ifndef WINDOW_H_
#define WINDOW_H_

enum projection {
    ISOMETRIC,
    PARALLEL
};

typedef struct window {
    map_t map;
    sfRenderWindow *window;
    enum projection mode;
    sfBool is_fullscreen;
    sfBool reload_window;
    int exit_status;
    int width;
    int height;
} window_t;

#endif
