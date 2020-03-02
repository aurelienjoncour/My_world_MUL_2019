/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** texture menu
*/

#include "my_world.h"

extern const int TEXTURE_COUNT;

static const sfVector2f MAIN_SPRITE_SIZE = {150, 150};
const sfVector2f SECO_SPRITE_SIZE = {100, 100};
const sfVector2f TEXTURE_INIT_SIZE = {32, 32};

static void set_sprite_position(texture_menu_t *self)
{
    sfVector2u win_size = self->size;
    sfVector2f main_pos = {(win_size.x / 2) - MAIN_SPRITE_SIZE.x / 2, 10};
    sfVector2f second_pos = {10, 40 + MAIN_SPRITE_SIZE.y};

    sfSprite_setPosition(self->spr_selected, main_pos);
    for (int i = 0; i < self->count_sprite; i++) {
        sfSprite_setPosition(self->spr_available[i], second_pos);
        second_pos.x += (SECO_SPRITE_SIZE.x + 10);
        if ((int)second_pos.x >= (int)win_size.x) {
            second_pos.x = 10;
            second_pos.y += (SECO_SPRITE_SIZE.y + 10);
        }
    }
}

static void set_sprite_scale(texture_menu_t *self)
{
    float seco_scale = SECO_SPRITE_SIZE.x / TEXTURE_INIT_SIZE.x;
    float main_scale = MAIN_SPRITE_SIZE.x / TEXTURE_INIT_SIZE.x;
    sfVector2f seco_scale_vec = {seco_scale, seco_scale};
    sfVector2f main_scale_vec = {main_scale, main_scale};

    sfSprite_setScale(self->spr_selected, main_scale_vec);
    for (int i = 0; i < self->count_sprite; i++) {
        sfSprite_setScale(self->spr_available[i], seco_scale_vec);
    }
}

int texture_menu_create_sprite(texture_menu_t *self)
{
    self->count_sprite = TEXTURE_COUNT - 1;
    self->spr_available = malloc(sizeof(sfSprite *) * self->count_sprite);
    if (!self->spr_available) {
        my_putstr_error("texture_menu_create : malloc error.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < self->count_sprite; i++) {
        self->spr_available[i] = sfSprite_create();
        sfSprite_setTexture(self->spr_available[i], self->map->textures[i + 1],
        sfTrue);
    }
    self->spr_selected = sfSprite_create();
    sfSprite_setTexture(self->spr_selected,
    self->map->textures[(*self->select_idx)], sfTrue);
    set_sprite_position(self);
    set_sprite_scale(self);
    return EXIT_SUCCESS;
}
