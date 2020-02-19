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

int button_set_locked(button_t *button, sfBool is_disabled);
int button_set_ischeckbox(button_t *button, sfBool is_checkbox);
int button_set_font(button_t *button, const char *path_font);
int button_set_charsize(button_t *button, unsigned int char_size);
int button_set_label(button_t *button, const char *label);
int button_set_color(button_t *button, sfColor *txt, sfColor *background);
int button_set_color_evt(button_t *button, sfColor *hover, sfColor *active);
void button_destroy(button_t *button);
int button_create(button_t *button, const char *label, const sfVector2f *size,
const sfVector2f *position);
void button_display(button_t *button, sfRenderWindow *window);
enum status button_get_status(button_t *button);
sfBool button_poll_event(button_t *button, int x, int y, enum status state);
int button_set_position(button_t *button, sfVector2f *position);
int button_set_size(button_t *button, sfVector2f *size);
void button_update_bg_color(button_t *button);

#endif
