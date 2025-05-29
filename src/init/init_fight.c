/*
** EPITECH PROJECT, 2024
** init_fight
** File description:
** init_fight
*/

#include "my.h"

fight_t *init_new_game_fight(game_t *game)
{
    fight_t *fight = malloc(sizeof(fight_t));

    fight->turn_order = NULL;
    fight->is_fight = false;
    fight->turn_order = 0;
    fight->target = 0;
    fight->fighter = 0;
    fight->gui = init_fight_gui(game->assets);
    fight->dep_mouv = (sfVector2f){300 + 100 * game->player->stats->MOVE, 300 +
        100 * game->player->stats->MOVE};
    fight->fired = false;
    fight->action = NO_ACTION;
    fight->action_taken = false;
    fight->gui->mana_img = init_image(get_asset("Fight_mov", game->assets),
        vect0(), 1);
    init_animated_img(fight->gui->mana_img, 38, 300, (sfVector2f){210, 500});
    set_animate_image(fight->gui->mana_img, 128, 128, 1);
    compute_mana_bar(fight);
    return fight;
}
