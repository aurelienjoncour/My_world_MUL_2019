/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** constant file
*/

#include "my_world.h"

const int WIN_HEIGHT = 1080;
const int WIN_WIDTH = 1920;
const int WIN_BPP = 32;
const unsigned int WIN_FRAMERATE = 30;

const sfVector3f MAP_INIT_SAMP = {64, 64, 10};
const sfVector2f MAP_INIT_ANGL = {45, 35};
const sfVector2f MAP_INIT_ORIG = {WIN_WIDTH / 2, WIN_HEIGHT / 8};
const int MAP_INIT_HEIGHT = 13;
const int MAP_INIT_WIDTH = 13;

const int EVT_MAP_TRANSLATE_DELTA = 10;
const float EVT_MAP_TRANSLATE_PERC = 0.1;
const float EVT_MAP_ROTATE_PERC = 0.03;
const int EVT_MAP_ROTATE_DELTA = 2;

const sfKeyCode KEY_MAP_TRANS_UP = sfKeyZ;
const sfKeyCode KEY_MAP_TRANS_DOWN = sfKeyS;
const sfKeyCode KEY_MAP_TRANS_LEFT = sfKeyQ;
const sfKeyCode KEY_MAP_TRANS_RIGHT = sfKeyD;

const sfKeyCode KEY_MAP_ROT_UP = sfKeyUp;
const sfKeyCode KEY_MAP_ROT_DOWN = sfKeyDown;
const sfKeyCode KEY_MAP_ROT_LEFT = sfKeyLeft;
const sfKeyCode KEY_MAP_ROT_RIGHT = sfKeyRight;
