/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_world.h"

extern const int EVT_MAP_TRANSLATE_DELTA;
extern const sfKeyCode KEY_MAP_TRANS_UP;
extern const sfKeyCode KEY_MAP_TRANS_DOWN;
extern const sfKeyCode KEY_MAP_TRANS_LEFT;
extern const sfKeyCode KEY_MAP_TRANS_RIGHT;

extern const int EVT_MAP_ROTATE_DELTA;
extern const sfKeyCode KEY_MAP_ROT_UP;
extern const sfKeyCode KEY_MAP_ROT_DOWN;
extern const sfKeyCode KEY_MAP_ROT_LEFT;
extern const sfKeyCode KEY_MAP_ROT_RIGHT;

static void event_key_zqsd(window_t *w, sfEvent *event)
{
    if (event->key.code == KEY_MAP_TRANS_UP) {
        map_translate(&w->map, 0, EVT_MAP_TRANSLATE_DELTA, w);
        map_translate(&w->map_water, 0, EVT_MAP_TRANSLATE_DELTA, w);
    }
    if (event->key.code == KEY_MAP_TRANS_DOWN) {
        map_translate(&w->map, 0, -EVT_MAP_TRANSLATE_DELTA, w);
        map_translate(&w->map_water, 0, -EVT_MAP_TRANSLATE_DELTA, w);
    }
    if (event->key.code == KEY_MAP_TRANS_LEFT) {
        map_translate(&w->map, EVT_MAP_TRANSLATE_DELTA, 0, w);
        map_translate(&w->map_water, EVT_MAP_TRANSLATE_DELTA, 0, w);
    }
    if (event->key.code == KEY_MAP_TRANS_RIGHT) {
        map_translate(&w->map_water, -EVT_MAP_TRANSLATE_DELTA, 0, w);
        map_translate(&w->map, -EVT_MAP_TRANSLATE_DELTA, 0, w);
    }
}

static void event_key_arrow(window_t *w, sfEvent *event)
{
    if (event->key.code == KEY_MAP_ROT_UP) {
        map_rotate(&w->map, 0, EVT_MAP_ROTATE_DELTA);
        map_rotate(&w->map_water, 0, EVT_MAP_ROTATE_DELTA);
    }
    if (event->key.code == KEY_MAP_ROT_DOWN) {
        map_rotate(&w->map, 0, -EVT_MAP_ROTATE_DELTA);
        map_rotate(&w->map_water, 0, -EVT_MAP_ROTATE_DELTA);
    }
    if (event->key.code == KEY_MAP_ROT_LEFT) {
        map_rotate(&w->map, EVT_MAP_ROTATE_DELTA, 0);
        map_rotate(&w->map_water, EVT_MAP_ROTATE_DELTA, 0);
    }
    if (event->key.code == KEY_MAP_ROT_RIGHT) {
        map_rotate(&w->map, -EVT_MAP_ROTATE_DELTA, 0);
        map_rotate(&w->map_water, -EVT_MAP_ROTATE_DELTA, 0);
    }
}

static void event_shortcut(window_t *w, sfEvent *event)
{
    if (event->key.code == sfKeyEscape)
        event_window_close(w);
    if (event->key.code == sfKeyR)
        map_reset(&w->map);
    if (event->key.code == sfKeyT)
        change_texture_display_mode(w);
    if (event->key.code == sfKeyH)
        image_viewer_status(&w->ui.help_menu_viewer, &w->state.help_menu);
    if (event->key.code == sfKeyP)
        map_scale_all(w, 1);
    if (event->key.code == sfKeyM)
        map_scale_all(w, -1);
    if (event->key.code == sfKeyW)
        action_gui_button_tool(&w->ui.raise, &w->state, &w->ui, RAISE);
    if (event->key.code == sfKeyX)
        action_gui_button_tool(&w->ui.lower, &w->state, &w->ui, LOWER);
    if (event->key.code == sfKeyC)
        action_gui_button_tool(&w->ui.level, &w->state, &w->ui, LEVEL);
    if (event->key.code == sfKeyV)
        action_gui_button_tool(&w->ui.texture, &w->state, &w->ui, TEXTURE);
}

void ctrl_shortcut(window_t *w, sfEvent *event)
{
    if (event->key.code == sfKeyS)
        action_map_save(w);
    if (event->key.code == sfKeyL)
        action_map_load(w);
    if (event->key.code == sfKeyR)
        map_generator(&w->map);
    if (event->key.code == sfKeyN) {
        text_input_run(&w->ui.edit_map_name, w->window);
        update_mape_name(w, text_input_get_input(&w->ui.edit_map_name));
    }
    if (event->key.code == sfKeyEqual)
        resize_shortcut(w, event, 1);
    if (event->key.code == sfKeyHyphen)
        resize_shortcut(w, event, -1);
}

void event_keypressed(window_t *w, sfEvent *event)
{
    if (event->key.control) {
        ctrl_shortcut(w, event);
        return;
    }
    event_shortcut(w, event);
    if (event->key.code == KEY_MAP_TRANS_UP ||
    event->key.code == KEY_MAP_TRANS_DOWN ||
    event->key.code == KEY_MAP_TRANS_LEFT ||
    event->key.code == KEY_MAP_TRANS_RIGHT) {
        event_key_zqsd(w, event);
    }
    if (event->key.code == KEY_MAP_ROT_UP ||
    event->key.code == KEY_MAP_ROT_DOWN ||
    event->key.code == KEY_MAP_ROT_LEFT ||
    event->key.code == KEY_MAP_ROT_RIGHT) {
        event_key_arrow(w, event);
    }
    action_object_move(w, event);
}
