/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_t
*/

#ifndef WINDOW_H_
#define WINDOW_H_

#include "ui_t.h"
#include "state_t.h"

enum projection {
    ISOMETRIC,
    PARALLEL
};

typedef struct window {
    object_t player;
    map_t map;
    map_t map_water;
    ui_t ui;
    state_t state;
    sound_manager_t sm;
    struct event evt;
    sfRenderWindow *window;
    enum projection mode;
    sfBool is_fullscreen;
    sfBool reload_window;
    int exit_status;
    int width;
    int height;
    sfClock *clock;
    sfInt32 timer;
    sfInt32 ms_loop;
} window_t;

#endif
