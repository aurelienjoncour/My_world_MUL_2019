/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** text input
*/

#include "my_world.h"

static const sfKeyCode KEY_ENTER = 58;
static const sfKeyCode KEY_4 = 51;
static const sfKeyCode KEY_6 = 56;

static const char ASCII_KEY[] =
{
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z',
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '_'
};

static const sfKeyCode CSFML_KEY[] =
{
    sfKeyA,
    sfKeyB,
    sfKeyC,
    sfKeyD,
    sfKeyE,
    sfKeyF,
    sfKeyG,
    sfKeyH,
    sfKeyI,
    sfKeyJ,
    sfKeyK,
    sfKeyL,
    sfKeyM,
    sfKeyN,
    sfKeyO,
    sfKeyP,
    sfKeyQ,
    sfKeyR,
    sfKeyS,
    sfKeyT,
    sfKeyU,
    sfKeyV,
    sfKeyW,
    sfKeyX,
    sfKeyY,
    sfKeyZ,
    sfKeyNum0,
    sfKeyNum1,
    sfKeyNum2,
    sfKeyNum3,
    KEY_4,
    sfKeyNum5,
    KEY_6,
    sfKeyNum7,
    sfKeyNum8,
    sfKeyNum9,
    sfKeyNumpad0,
    sfKeyNumpad1,
    sfKeyNumpad2,
    sfKeyNumpad3,
    sfKeyNumpad4,
    sfKeyNumpad5,
    sfKeyNumpad6,
    sfKeyNumpad7,
    sfKeyNumpad8,
    sfKeyNumpad9,
    sfKeySpace
};

static const int KEY_ARRAY_SIZE = 47;

static int get_index(sfKeyCode code)
{
    for (int i = 0; i < KEY_ARRAY_SIZE; i++) {
        if (CSFML_KEY[i] == code) {
            return i;
        }
    }
    return (-1);
}

static void text_input_keypressed(text_in_t *in, sfKeyCode code)
{
    int index;

    if (code == sfKeyBack && in->i_buffer > 1) {
        in->i_buffer--;
        in->buffer[in->i_buffer] = '\0';
        sfText_setString(in->text, in->buffer);
    } else if (code == KEY_ENTER) {
        sfRenderWindow_close(in->window);
    } else {
        printf("code : %d - %d \n", code, sfKeySpace);
        index = get_index(code);
        if (index != -1 && in->i_buffer < (int)(in->max_char - 1)) {
            in->buffer[in->i_buffer++] = ASCII_KEY[index];
            in->buffer[in->i_buffer] = '\0';
            sfText_setString(in->text, in->buffer);
        }
    }
}

static void text_input_event_manager(text_in_t *in, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(in->window);
    } else if (event->type == sfEvtKeyPressed) {
        text_input_keypressed(in, event->key.code);
    }
}

int text_input_run(text_in_t *in, sfRenderWindow *parent_window)
{
    sfEvent event;
    sfVector2i pos = {700, 400};

    sfRenderWindow_setVisible(parent_window, sfFalse);
    sfRenderWindow_setPosition(in->window, pos);
    while (sfRenderWindow_isOpen(in->window)) {
        while (sfRenderWindow_pollEvent(in->window, &event))
            text_input_event_manager(in, &event);
        sfRenderWindow_clear(in->window, in->color_bg);
        sfRenderWindow_drawText(in->window, in->text, NULL);
        sfRenderWindow_display(in->window);
    }
    sfRenderWindow_setVisible(parent_window, sfTrue);
    return EXIT_SUCCESS;
}
