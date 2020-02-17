/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include <stdlib.h>
#include "my_world.h"

extern const int WIN_HEIGHT;
extern const int WIN_WIDTH;
extern const int WIN_BIN_BPP;

sfRenderWindow *create_windows(void)
{
    sfVideoMode video_mode = {WIN_WIDTH, WIN_HEIGHT, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(video_mode, "My World",
            sfDefaultStyle, NULL);
    return window;
}

int main(void)
{
    sfRenderWindow *window = create_windows();
    sfEvent event;
    map_t map;

    map_create(&map, 6, 6);
    while (sfRenderWindow_isOpen(window)) {
        map_display(window, &map);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
                sfRenderWindow_close(window);
        }
    }
    return EXIT_SUCCESS;
}
