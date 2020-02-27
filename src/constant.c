/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** constant file
*/

#include "my_world.h"

// WINDOW PAREMETERS
const int WIN_HEIGHT = 1080;
const int WIN_WIDTH = 1920;
const int WIN_BPP = 32;
const unsigned int WIN_FRAMERATE = 30;

// MAP PARAMETERS
const char *DEFAULT_MAP_NAME = "undefined";
const char *MAP_EXTENSION = ".world";

const sfVector3f MAP_INIT_SAMP = {32, 32, 5};
const sfVector2f MAP_INIT_ANGL = {45, 35};
const sfVector2f MAP_INIT_ORIG = {WIN_WIDTH / 2, 0};
const int MAP_INIT_HEIGHT = 40;
const int MAP_INIT_WIDTH = 40;
const sfColor MAP_LINE_COLOR = {255, 255, 255, 255};

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

// BUTTON PARAMETERS
const unsigned int BUTTON_INIT_CHARSIZE = 30;
const sfColor BUTTON_INIT_COLORBG = (sfColor){255, 255, 255, 255};
const sfColor BUTTON_INIT_COLORTXT = (sfColor){0, 0, 0, 255};
const sfColor BUTTON_INIT_COLORHOV = (sfColor){128, 128, 128, 255};
const sfColor BUTTON_INIT_COLORACT = (sfColor){75, 75, 75, 255};
const char *BUTTON_INIT_FONT = "./asset/font/BebasNeue-Regular.ttf";

// TEXT INPUT PARAMETERS
const sfVector2f TEXT_IN_INIT_POS = (sfVector2f){4, 4};
const unsigned int TEXT_IN_INIT_CHARSIZE = 50;
const sfColor TEXT_IN_INIT_TXTCOLOR = (sfColor){255, 255, 255, 255};
const sfColor TEXT_IN_INIT_BGCOLOR = (sfColor){55, 55, 55, 255};
const char *TEXT_IN_INIT_FONT = "./asset/font/BebasNeue-Regular.ttf";
const unsigned int TEXT_IN_INIT_HEIGHT = 60;
const unsigned int TEXT_IN_INIT_CHAR_WIDTH = 28;
const unsigned int TEXT_IN_INIT_WIN_FPS = 30;

// GUI PARAMETERS : Cursor circle
const float CIRCLE_CLICK_RADIUS = 5.0f;
const sfInt32 MS_UPDATE_PANEL = 100;

// Help menu
const char *HELP_MENU_TITLE = "Help menu";
const char *HELP_MENU_FILEPATH = "./asset/img/man.jpg";

// GUI text
const char *GUI_TEXT_FONT = "./asset/font/monofonto.ttf";
const unsigned int GUI_TEXT_SIZE = 20;
const sfColor GUI_TEXT_COLOR = (sfColor){255, 255, 255, 255};

// Texture

const int TEXTURE_COUNT = 6;
const char *TEXTURE_PATH[] =
{
    "asset/img/black.png",
    "asset/img/water.jpg",
    "asset/img/dirt.png",
    "asset/img/cobblestone.png",
    "asset/img/stone.png",
    "asset/img/snow.png"
};
const int TXTR_WATER = 1;
const int TXTR_DIRT = 2;
const int TXTR_COBBLESTONE = 3;
const int TXTR_STONE = 4;
const int TXTR_SNOW = 5;

// Sound
const char *SOUND_PATH[] =
{
    "./asset/sound/start.ogg",
    "./asset/sound/click.ogg"
};
const float SOUND_VOLUME = 80;
const float SOUND_VOLUME_MUSIC = 50;
