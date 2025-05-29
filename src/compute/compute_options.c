/*
** EPITECH PROJECT, 2024
** analyze_options
** File description:
** analyze_options
*/

#include "my.h"
#include "gui_struct.h"
#include <stdlib.h>

static void update_state_button_retour(gui_obj_t *button, guis_t *guis,
    game_t *game)
{
    if (button->state == RELEASED) {
        if (game->retour_options_in_game == sfFalse)
            guis->active = MAIN_MENU;
        else
            guis->active = MAP;
        button->state = NO_STATE;
        game->retour_options_in_game = sfFalse;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_fullscreen(button_t *button, game_t *game)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    if (button->gui_obj->state == RELEASED) {
        change_window(game, true);
        button->gui_obj->state = NO_STATE;
        if (game->retour_options_in_game == sfFalse)
            return (compute_default_state_button(button));
        else {
            game->guis->active = MAP;
            game->retour_options_in_game = sfFalse;
            map->inventory->is_display = false;
            reset_postion_items(map);
            map->inventory->is_picked = false;
            map->inventory->items_slots_picked = -1;
            game->espace_active = !game->espace_active;
            game->events->key.code = sfKeyCount;
        }
    }
    compute_default_state_button(button);
}

static void update_state_button_lower_volume(gui_obj_t *button,
    game_t *game, page_options_t *options)
{
    if (button->state == RELEASED) {
        if (game->music->music_volume > 5)
            game->music->music_volume -= 5.;
        else
            game->music->music_volume = 0.;
        button->state = NO_STATE;
        change_txt_volume(options, game);
        set_general_volume(game);
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_greater_volume(gui_obj_t *button, game_t *game,
    page_options_t *options)
{
    if (button->state == RELEASED) {
        if (game->music->music_volume < 95)
            game->music->music_volume += 5.;
        else
            game->music->music_volume = 100;
        button->state = NO_STATE;
        change_txt_volume(options, game);
        set_volume_for_musics(game->music, game->music->music_volume);
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_unmute_volume(button_t *button)
{
    if (button->gui_obj->state == RELEASED) {
        button->gui_obj->state = NO_STATE;
    }
    compute_default_state_button(button);
}

static void update_state_button_mute_volume(button_t *button, game_t *game)
{
    if (button->gui_obj->state == RELEASED) {
        if (game->music->mute_volume == sfTrue) {
            game->music->mute_volume = sfFalse;
            set_volume_for_musics(game->music, game->music->music_volume);
            set_volume_for_sounds(game->sounds, game->sounds->sound_volume);
        } else {
            game->music->mute_volume = sfTrue;
            set_volume_for_musics(game->music, 0);
            set_volume_for_sounds(game->sounds, 0);
        }
        button->gui_obj->state = NO_STATE;
    }
    compute_default_state_button(button);
}

static void resolution_button_set(button_t *button, game_t *game)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    button->gui_obj->state = NO_STATE;
    if (game->retour_options_in_game == sfFalse)
        return (compute_default_state_button(button));
    else {
        game->guis->active = MAP;
        game->retour_options_in_game = sfFalse;
        map->inventory->is_display = false;
        reset_postion_items(map);
        map->inventory->is_picked = false;
        map->inventory->items_slots_picked = -1;
        game->espace_active = !game->espace_active;
        game->events->key.code = sfKeyCount;
    }
}

static void update_state_button_resolution(button_t *button,
    game_t *game, int resolution_size)
{
    if (button->gui_obj->state == RELEASED) {
        if (resolution_size == 0) {
            game->video_mode = (sfVideoMode){1280, 720, 32};
            change_window(game, false);
        }
        if (resolution_size == 1) {
            game->video_mode = (sfVideoMode){1366, 768, 32};
            change_window(game, false);
        }
        if (resolution_size == 2) {
            game->video_mode = (sfVideoMode){1920, 1080, 32};
            change_window(game, false);
        }
        resolution_button_set(button, game);
    }
    compute_default_state_button(button);
}

static void update_state_button_save(button_t *button, game_t *game)
{
    if (((map_t *)(game->guis->map->ui_content))->fight->is_fight) {
        sfSprite_setColor(button->gui_obj->img->sprite, TRANSPARENT);
        sfText_setColor(button->text->txt, TRANSPARENT);
    } else {
        sfSprite_setColor(button->gui_obj->img->sprite, sfWhite);
        sfText_setColor(button->text->txt, sfWhite);
        if (button->gui_obj->state == RELEASED) {
            save_data(game);
            button->gui_obj->state = NO_STATE;
        }
        compute_default_state_button(button);
    }
}

void compute_options(ui_obj_t *obj, game_t *game)
{
    page_options_t *options = (page_options_t *)obj->ui_content;

    update_pos_sprites_options(game, options);
    if (check_keybinds_wait(game, options) == 1)
        return;
    update_state_button_retour(options->retour, game->guis, game);
    update_state_button_fullscreen(options->fullscreen, game);
    update_state_button_mute_volume(options->mute_volume, game);
    update_state_button_unmute_volume(options->unmute_volume);
    update_state_button_lower_volume(options->lower_volume, game, options);
    update_state_button_greater_volume(options->greater_volume, game, options);
    update_state_button_mute_volume(options->mute_volume, game);
    update_state_button_unmute_volume(options->unmute_volume);
    update_state_button_resolution(options->min_resolution, game, 0);
    update_state_button_resolution(options->mid_resolution, game, 1);
    update_state_button_resolution(options->max_resolution, game, 2);
    update_state_button_save(options->save, game);
    compute_sound(game, obj);
    change_txt_volume(options, game);
    change_txt_sound(options, game);
}
