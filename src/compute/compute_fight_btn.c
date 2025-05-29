/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

bool player_second_action(game_t *game)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    if (map->player->class == SOLO && map->fight->dep_mouv.x == map->fight
        ->dep_mouv.y && map->fight->action_taken == true)
        return true;
    return false;
}

static void compute_player_actions_fire(ui_obj_t *obj, game_t *game)
{
    fight_t *fight = ((map_t *)obj->ui_content)->fight;
    gui_obj_t *button = ((map_t *)obj->ui_content)->fight->gui->fire;
    static enum gui_state_e prev_fire = NO_STATE;

    if (fight->gui->mode == true)
        button = ((map_t *)obj->ui_content)->fight->gui->autofire;
    if (btn_is_pressed(button->state, prev_fire) == sfTrue &&
        (!fight->action_taken || player_second_action(game)))
        fire(obj, game);
    prev_fire = button->state;
    if (fight->action_taken && !player_second_action(game)) {
        sfSprite_setColor(button->img->sprite, (sfColor){60, 60, 60, 255});
        return;
    } else
        sfSprite_setColor(button->img->sprite, sfWhite);
    compute_usual_state(button);
}

static void compute_player_actions_expl(ui_obj_t *obj, game_t *game)
{
    fight_t *fight = ((map_t *)obj->ui_content)->fight;
    gui_obj_t *button = ((map_t *)obj->ui_content)->fight->gui->expl;
    static enum gui_state_e prev_expl = NO_STATE;

    if (btn_is_pressed(button->state, prev_expl) == sfTrue &&
        (!fight->action_taken || player_second_action(game)))
        fire(obj, game);
    prev_expl = button->state;
    if (fight->action_taken && !player_second_action(game)) {
        sfSprite_setColor(button->img->sprite, (sfColor){60, 60, 60, 255});
        return;
    } else
        sfSprite_setColor(button->img->sprite, sfWhite);
    compute_usual_state(button);
}

static void compute_player_actions_shell(ui_obj_t *obj, game_t *game)
{
    fight_t *fight = ((map_t *)obj->ui_content)->fight;
    gui_obj_t *button = ((map_t *)obj->ui_content)->fight->gui->shell;
    static enum gui_state_e prev_shell = NO_STATE;

    if (btn_is_pressed(button->state, prev_shell) == sfTrue &&
        (!fight->action_taken || player_second_action(game)))
        fire(obj, game);
    prev_shell = button->state;
    if (fight->action_taken && !player_second_action(game)) {
        sfSprite_setColor(button->img->sprite, (sfColor){60, 60, 60, 255});
        return;
    } else
        sfSprite_setColor(button->img->sprite, sfWhite);
    compute_usual_state(button);
}

static void compute_player_actions_bow(ui_obj_t *obj, game_t *game)
{
    fight_t *fight = ((map_t *)obj->ui_content)->fight;
    gui_obj_t *button = ((map_t *)obj->ui_content)->fight->gui->bow;
    static enum gui_state_e prev_bow = NO_STATE;

    if (btn_is_pressed(button->state, prev_bow) == sfTrue &&
        (!fight->action_taken || player_second_action(game)))
        fire(obj, game);
    prev_bow = button->state;
    if (fight->action_taken && !player_second_action(game)) {
        sfSprite_setColor(button->img->sprite, (sfColor){60, 60, 60, 255});
        return;
    } else
        sfSprite_setColor(button->img->sprite, sfWhite);
    compute_usual_state(button);
}

static void compute_player_actions_unarmd(ui_obj_t *obj, game_t *game)
{
    fight_t *fight = ((map_t *)obj->ui_content)->fight;
    gui_obj_t *button = ((map_t *)obj->ui_content)->fight->gui->unarmd;
    static enum gui_state_e prev_unarmd = NO_STATE;

    if (btn_is_pressed(button->state, prev_unarmd) == sfTrue &&
        (!fight->action_taken || player_second_action(game)))
        fire(obj, game);
    prev_unarmd = button->state;
    if (fight->action_taken && !player_second_action(game)) {
        sfSprite_setColor(button->img->sprite, (sfColor){60, 60, 60, 255});
        return;
    } else
        sfSprite_setColor(button->img->sprite, sfWhite);
    compute_usual_state(button);
}

static void compute_player_actions_melee(ui_obj_t *obj, game_t *game)
{
    fight_t *fight = ((map_t *)obj->ui_content)->fight;
    gui_obj_t *button = ((map_t *)obj->ui_content)->fight->gui->melee;
    static enum gui_state_e prev_melee = NO_STATE;

    if (btn_is_pressed(button->state, prev_melee) == sfTrue &&
        (!fight->action_taken || player_second_action(game)))
        fire(obj, game);
    prev_melee = button->state;
    if (fight->action_taken && !player_second_action(game)) {
        sfSprite_setColor(button->img->sprite, (sfColor){60, 60, 60, 255});
        return;
    } else
        sfSprite_setColor(button->img->sprite, sfWhite);
    compute_usual_state(button);
}

static void compute_player_actions_autofire(ui_obj_t *obj, game_t *game)
{
    fight_t *fight = ((map_t *)obj->ui_content)->fight;
    gui_obj_t *button = ((map_t *)obj->ui_content)->fight->gui->autofire;
    static enum gui_state_e prev_autofire = NO_STATE;

    if (fight->gui->mode == true)
        button = ((map_t *)obj->ui_content)->fight->gui->fire;
    if (btn_is_pressed(button->state, prev_autofire) == sfTrue)
        fight->gui->mode = 1 - fight->gui->mode;
    prev_autofire = button->state;
    if (fight->action_taken && !player_second_action(game)) {
        sfSprite_setColor(button->img->sprite, (sfColor){60, 60, 60, 255});
        return;
    } else
        sfSprite_setColor(button->img->sprite, sfWhite);
    compute_usual_state(button);
    (void) game;
}

void compute_player_fight(ui_obj_t *obj, game_t *game)
{
    compute_movement(obj, game);
    compute_player_actions_done(obj, game);
    compute_player_actions_dash(obj, game);
    compute_player_actions_dodge(obj, game);
    compute_player_actions_fire(obj, game);
    compute_player_actions_autofire(obj, game);
    compute_player_actions_expl(obj, game);
    compute_player_actions_shell(obj, game);
    compute_player_actions_bow(obj, game);
    compute_player_actions_unarmd(obj, game);
    compute_player_actions_melee(obj, game);
}
