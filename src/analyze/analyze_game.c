/*
** EPITECH PROJECT, 2024
** analyze_game
** File description:
** analyze_game
*/

#include "my.h"

void analyze_escape_key(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyEscape
        && game->guis->active == MAP) {
        game->retour_options_in_game = sfTrue;
        game->guis->active = OPTIONS;
    } else if (event->type == sfEvtKeyReleased
        && event->key.code == sfKeyEscape
        && game->guis->active == OPTIONS && game->retour_options_in_game) {
        game->retour_options_in_game = sfFalse;
        game->guis->active = MAP;
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyEscape
        && game->guis->active == OPTIONS && !game->retour_options_in_game) {
        game->guis->active = MAIN_MENU;
    }
}

void analyze_game(game_t *game)
{
    analyze_guis(game->guis, game);
}
