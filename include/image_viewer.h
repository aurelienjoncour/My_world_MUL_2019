/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** image viewer widget header
*/

#ifndef IMG_VIEW_H
#define IMG_VIEW_H

typedef struct image_viewer_widget {
    sfVector2u size;
    char *title;
    char *file_path;
    sfTexture* texture;
    sfSprite* sprite;
    sfRenderWindow *window;
} img_view_t;

int image_viewer_create(img_view_t *self, const char *file_name,
const char *title);
void image_viewer_destroy(img_view_t *self);

int image_viewer_run(img_view_t *self, sfRenderWindow *parent_window);

#endif
