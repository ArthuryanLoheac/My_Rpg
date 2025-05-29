/*
** EPITECH PROJECT, 2024
** make_game
** File description:
** make_game
*/

#include "my.h"

void make_game(game_t *game)
{
    make_guis(game->guis, game);
    if (game->guis->active == MAP)
        make_info(game->window, game->info);
}
