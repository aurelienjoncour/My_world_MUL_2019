/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** text input widget header
*/

#ifndef TXT_IN_H
#define TXT_IN_H

typedef struct text_input_widget {
    sfVector2u size;
    unsigned int max_char;
    unsigned int charsize;
    char *title;
    char *buffer;
    int i_buffer;
    sfText *text;
    sfFont *font;
    sfColor color_bg;
    sfColor color_txt;
    sfRenderWindow *window;
} text_in_t;

int text_input_create(text_in_t *input, const char *title,
unsigned int max_char, const char *init_buffer);
void text_input_destroy(text_in_t *input);

int text_input_run(text_in_t *in, sfRenderWindow *parent_window);

char *text_input_get_input(text_in_t *input);

int text_input_set_size(text_in_t *in, unsigned int sizex, unsigned int sizey);
int text_input_set_color(text_in_t *in, sfColor *bg_color, sfColor *txt_color);
int text_input_set_charsize(text_in_t *in, unsigned int size);
int text_input_set_font(text_in_t *in, const char *path_font);

#endif
