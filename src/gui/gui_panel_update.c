/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** gui label update
*/

#include "my_world.h"

static void update_angle(window_t *w)
{
    char *base[3] = {"Angle: (", " deg, ", " deg)"};
    char *valx = my_putnbr_base_str((int)w->map.angle.x, "0123456789");
    char *valy = my_putnbr_base_str((int)w->map.angle.y, "0123456789");
    char *alpha = my_str_concat(base[0], valx);
    char *beta = my_str_concat(base[1], valy);
    char *charlie = my_str_concat(alpha, beta);
    char *delta = my_str_concat(charlie, base[2]);

    free(valx);
    free(valy);
    free(alpha);
    free(beta);
    free(charlie);
    if (delta)
        sfText_setString(w->ui.txt_angle, delta);
    free(delta);
}

static void update_origin(window_t *w)
{
    char *base[3] = {"Origin: (", ", ", ")"};
    char *valx = my_putnbr_base_str((int)w->map.origin.x, "0123456789");
    char *valy = my_putnbr_base_str((int)w->map.origin.y, "0123456789");
    char *alpha = my_str_concat(base[0], valx);
    char *beta = my_str_concat(base[1], valy);
    char *charlie = my_str_concat(alpha, beta);
    char *delta = my_str_concat(charlie, base[2]);

    free(valx);
    free(valy);
    free(alpha);
    free(beta);
    free(charlie);
    if (delta)
        sfText_setString(w->ui.txt_origin, delta);
    free(delta);
}

static void update_size(window_t *w)
{
    char *base[3] = {"Size: (", ", ", ")"};
    char *valx = my_putnbr_base_str(w->map.height, "0123456789");
    char *valy = my_putnbr_base_str(w->map.width, "0123456789");
    char *alpha = my_str_concat(base[0], valx);
    char *beta = my_str_concat(base[1], valy);
    char *charlie = my_str_concat(alpha, beta);
    char *delta = my_str_concat(charlie, base[2]);

    free(valx);
    free(valy);
    free(alpha);
    free(beta);
    free(charlie);
    if (delta)
        sfText_setString(w->ui.txt_size, delta);
    free(delta);
}

static void update_scale(window_t *w)
{
    char *base[4] = {"Scale: (", ", ", ", ", ")"};
    char *sect[6] = {NULL};
    char *valx = my_putnbr_base_str(w->map.sampling.x, "0123456789");
    char *valy = my_putnbr_base_str(w->map.sampling.y, "0123456789");
    char *valz = my_putnbr_base_str(w->map.sampling.z, "0123456789");

    sect[0] = my_str_concat(base[0], valx);
    sect[1] = my_str_concat(base[1], valy);
    sect[2] = my_str_concat(base[2], valz);
    sect[3] = my_str_concat(sect[0], sect[1]);
    sect[4] = my_str_concat(sect[2], base[3]);
    sect[5] = my_str_concat(sect[3], sect[4]);
    if (sect[5])
        sfText_setString(w->ui.txt_scale, sect[5]);
    free(valx);
    free(valy);
    free(valz);
    for (int i = 0; i < 6; i++)
        free(sect[i]);
}

int gui_panel_update(window_t *w)
{
    update_angle(w);
    update_origin(w);
    update_size(w);
    update_scale(w);
    return EXIT_SUCCESS;
}
