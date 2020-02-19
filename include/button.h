/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** button widget header
*/

#ifndef BUTTON_H
#define BUTTON_H

typedef unsigned int uint;

enum status {
    NONE,
    HOVER,
    ACTIVE
};

typedef struct button_widget {
    char *label;
    uint char_size;
    sfFont *font;
    sfColor color_bg;
    sfColor color_txt;
    sfColor color_hover;
    sfColor color_active;
    sfText *text;
    sfRectangleShape *rect;
    sfVector2f position;
    sfVector2f size;
    sfBool is_disabled;
    sfBool is_checkbox;
    enum status state;
} button_t;

#endif
