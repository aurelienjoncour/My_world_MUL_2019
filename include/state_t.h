/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** state_t
*/

#ifndef STATE_T_H_
#define STATE_T_H_

enum view_mode {
    NONE,
    SCALE,
    TRANSLATE;
    ROTATE
};

enum tools {
    NONE,
    RAISE,
    LOWER,
    LEVEL,
    TEXTURE
};

enum select_modes {
    PLANE,
    EDGE,
    CORNER
};

enum status {
    NONE,
    MORE,
    LESS
};

typedef struct software_status {
    enum view_mode vmode;
    sfBool show_help_menu;
    sfBool map_random_gen;
    sfBool map_edit_name;
    sfBool map_load;
    sfBool map_save;
    sfBool map_reset;
    enum tools tool;
    enum status map_size_x;
    enum status map_size_y;
    enum select_modes select_mode;
} state_t;

#endif
