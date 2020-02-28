/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** sound manager object
*/

#include "my_world.h"

extern const char *SOUND_PATH[];
extern const float SOUND_VOLUME;
extern const float SOUND_VOLUME_MUSIC;

void sound_manager_destroy(sound_manager_t *sm)
{
    for (int i = 0; i < SOUND_COUNT; i++) {
        if (sm->sounds[i])
            sfMusic_destroy(sm->sounds[i]);
    }
}

void sound_manager_play(sound_manager_t *sm, int id_sound)
{
    if (id_sound < 0 || id_sound >= SOUND_COUNT) {
        my_putstr_error("ERROR: sound_manager_play : invalid sound id.\n");
        return;
    }
    sfMusic_stop(sm->sounds[id_sound]);
    sfMusic_play(sm->sounds[id_sound]);
}

int sound_manager_create(sound_manager_t *sm)
{
    for (int i = 0; i < SOUND_COUNT; i++) {
        sm->sounds[i] = sfMusic_createFromFile(SOUND_PATH[i]);
        if (!sm->sounds[i]) {
            my_putstr_error("ERROR: load sound\n");
            return EXIT_FAILURE;
        }
        sfMusic_setVolume(sm->sounds[i], SOUND_VOLUME);
    }
    sfMusic_setVolume(sm->sounds[SOUND_START], SOUND_VOLUME_MUSIC);
    sfMusic_setVolume(sm->sounds[SOUND_MUSIC], SOUND_VOLUME_MUSIC * 10);
    return EXIT_SUCCESS;
}
