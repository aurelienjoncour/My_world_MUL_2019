/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** header
*/

#ifndef H_SOUND
#define H_SOUND

#include <SFML/Audio.h>

#define SOUND_COUNT 3

#define SOUND_START 0
#define SOUND_CLICK 1
#define SOUND_MUSIC 2

typedef struct sound_manager {
    sfMusic *sounds[SOUND_COUNT];
} sound_manager_t;

void sound_manager_destroy(sound_manager_t *sm);
void sound_manager_play(sound_manager_t *sm, int id_sound);
int sound_manager_create(sound_manager_t *sm);

#endif
