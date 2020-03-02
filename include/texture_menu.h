/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** Texture menu window
*/

#ifndef TEXTURE_MENU_H
#define TEXTURE_MENU_H

typedef struct texture_menu {
    sfRenderWindow *window;
    sfVector2u size;
    sfText *txt_info;
    sfFont *font;
    sfColor color_bg;
    sfColor color_txt;
    sfSprite *spr_selected;
    sfSprite **spr_available;
    int count_sprite;
    int *select_idx;
    map_t *map;
} texture_menu_t;

int texture_menu_create(texture_menu_t *self, map_t *map);
int texture_menu_create_sprite(texture_menu_t *self);

void texture_menu_destroy(texture_menu_t *self);

int texture_menu_display(texture_menu_t *self, map_t *map, sfBool *is_active);

int texture_menu_status(texture_menu_t *self, sfBool *state);

#endif
