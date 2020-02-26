/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** gui_create
*/

#include "my_world.h"

extern const char *GUI_TEXT_FONT;
extern const unsigned int GUI_TEXT_SIZE;
extern const sfColor GUI_TEXT_COLOR;

static int label_create(sfText **text, sfFont *font, const char *label,
sfVector2f pos)
{
    *text = sfText_create();
    if (!*text)
        return EXIT_ERROR;
    sfText_setFont(*text, font);
    sfText_setCharacterSize(*text, GUI_TEXT_SIZE);
    sfText_setColor(*text, GUI_TEXT_COLOR);
    sfText_setString(*text, label);
    sfText_setPosition(*text, pos);
    return EXIT_SUCCESS;
}

#define V2F(x, y) (sfVector2f){x, y}

int gui_label_create(window_t *w)
{
    w->ui.font = sfFont_createFromFile(GUI_TEXT_FONT);
    if (!w->ui.font)
        return EXIT_FAILURE;
    if (label_create(&w->ui.txt_map_name, w->ui.font, w->map.map_name,
    V2F(w->width / 2 - 50, 40)))
        return EXIT_FAILURE;
    if (label_create(&w->ui.txt_select_mode, w->ui.font, "TILE", V2F(5, 940)))
        return EXIT_FAILURE;
    if (label_create(&w->ui.txt_angle, w->ui.font, "Angle:", V2F(5, 5)))
        return EXIT_FAILURE;
    if (label_create(&w->ui.txt_origin, w->ui.font, "Origin:", V2F(5, 40)))
        return EXIT_FAILURE;
    if (label_create(&w->ui.txt_scale, w->ui.font, "Scale:", V2F(5, 75)))
        return EXIT_FAILURE;
    if (label_create(&w->ui.txt_size, w->ui.font, "Size:", V2F(5, 110)))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
