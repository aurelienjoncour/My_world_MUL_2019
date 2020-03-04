/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slider
*/

#ifndef SLIDER_H_
#define SLIDER_H_

struct window;

typedef struct slider_widget {
    sfColor color;
    sfRectangleShape *rect;
    sfCircleShape *circle;
    sfVector2f circle_pos;
    sfVector2f rect_pos;
    sfVector2f rect_size;
    float circle_radius;
    sfBool isPressed;
    int min;
    int max;
} slider_t;

void slider_display(slider_t *slider, sfRenderWindow *window);
int slider_create(slider_t *slider, sfVector2f position, float length);
int slider_destroy(slider_t *slider);
int check_event_slider(slider_t *slider, enum button_status status,
sfVector2i mouse, struct window *w);
float slider_get_value(slider_t *slider);

#endif /* !SLIDER_H_ */
