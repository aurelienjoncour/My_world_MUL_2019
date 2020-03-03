/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** texture menu
*/

#include "my_world.h"

extern const int WIN_BPP;
extern const unsigned int WIN_FRAMERATE;
extern const char *GUI_TEXT_FONT;

extern const sfVector2f SECO_SPRITE_SIZE;

static const char *WINDOW_TITLE = "Texture Menu";
static const char *TEXT_INFO = "< Switch texture with the arrow key >";
static const sfVector2u WINDOW_SIZE = {800, 400};
static const sfVector2f TEXT_POS = {200, 480};

static int texture_menu_create_window(texture_menu_t *self)
{
    sfVideoMode mode = {self->size.x, self->size.y, WIN_BPP};

    self->window = sfRenderWindow_create(mode, WINDOW_TITLE, sfClose,
    sfContextDefault);
    if (!self->window) {
        my_putstr_error("texture_menu_create_window : error.\n");
        return EXIT_FAILURE;
    }
    sfRenderWindow_setFramerateLimit(self->window, WIN_FRAMERATE);
    sfRenderWindow_setVisible(self->window, sfFalse);
    return EXIT_SUCCESS;
}

static int texture_menu_create_text(texture_menu_t *self)
{
    sfVector2f txt_pos = TEXT_POS;

    self->font = sfFont_createFromFile(GUI_TEXT_FONT);
    self->txt_info = sfText_create();
    if (!self->txt_info || !self->font) {
        my_putstr_error("texture_menu_create : error text or font create\n");
        return EXIT_FAILURE;
    }
    sfText_setFont(self->txt_info, self->font);
    txt_pos.y = self->size.y - 30;
    sfText_setPosition(self->txt_info, txt_pos);
    sfText_setString(self->txt_info, TEXT_INFO);
    sfText_setColor(self->txt_info, self->color_txt);
    sfText_setCharacterSize(self->txt_info, 20);
    return EXIT_SUCCESS;
}

static void texture_menu_compute_window_height(texture_menu_t *self)
{
    float sprite_per_line = ((double)WINDOW_SIZE.x / SECO_SPRITE_SIZE.x);
    float excess = 0;
    float excess_lines = 0;

    if (sprite_per_line < self->count_sprite) {
        excess = (float)self->count_sprite - sprite_per_line;
        excess_lines = ceil(excess / sprite_per_line);
        self->size.y += (SECO_SPRITE_SIZE.y + 10) * excess_lines;
    }
}

int texture_menu_create(texture_menu_t *self, map_t *map)
{
    if (!self || !map)
        return EXIT_FAILURE;
    self->map = map;
    self->select_idx = &map->selected_texture;
    self->size = WINDOW_SIZE;
    self->color_bg = (sfColor){40, 40, 40, 255};
    self->color_txt = sfWhite;
    if (texture_menu_create_sprite(self) == EXIT_FAILURE)
        return EXIT_FAILURE;
    texture_menu_compute_window_height(self);
    if (texture_menu_create_text(self) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (texture_menu_create_window(self) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void texture_menu_destroy(texture_menu_t *self)
{
    sfRenderWindow_destroy(self->window);
    sfFont_destroy(self->font);
    sfText_destroy(self->txt_info);
    sfSprite_destroy(self->spr_selected);
    for (int i = 0; i < self->count_sprite; i++) {
        sfSprite_destroy(self->spr_available[i]);
    }
    free(self->spr_available);
}
