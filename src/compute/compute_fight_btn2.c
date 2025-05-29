/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

void compute_player_actions_done(ui_obj_t *obj, game_t *game)
{
    gui_obj_t *button = ((map_t *)obj->ui_content)->fight->gui->done;
    static enum gui_state_e prev_done = NO_STATE;

    if (btn_is_pressed(button->state, prev_done) == sfTrue)
        done((map_t *)obj->ui_content);
    prev_done = button->state;
    (void) game;
    compute_usual_state(button);
}

void compute_player_actions_dash(ui_obj_t *obj, game_t *game)
{
    fight_t *fight = ((map_t *)obj->ui_content)->fight;
    gui_obj_t *button = ((map_t *)obj->ui_content)->fight->gui->dash;
    static enum gui_state_e prev_dash = NO_STATE;

    if (btn_is_pressed(button->state, prev_dash) == sfTrue &&
        !fight->action_taken)
        dash(obj, game);
    prev_dash = button->state;
    if (fight->action_taken == true) {
        sfSprite_setColor(button->img->sprite, (sfColor){60, 60, 60, 255});
        return;
    } else
        sfSprite_setColor(button->img->sprite, sfWhite);
    compute_usual_state(button);
}

void compute_player_actions_dodge(ui_obj_t *obj, game_t *game)
{
    fight_t *fight = ((map_t *)obj->ui_content)->fight;
    gui_obj_t *button = ((map_t *)obj->ui_content)->fight->gui->dodge;
    static enum gui_state_e prev_dodge = NO_STATE;

    if (btn_is_pressed(button->state, prev_dodge) == sfTrue &&
        !fight->action_taken)
        dodge(obj, game);
    prev_dodge = button->state;
    if (fight->action_taken == true) {
        sfSprite_setColor(button->img->sprite, (sfColor){60, 60, 60, 255});
        return;
    } else
        sfSprite_setColor(button->img->sprite, sfWhite);
    compute_usual_state(button);
}
