/*
** EPITECH PROJECT, 2024
** compute_game
** File description:
** compute_game
*/

#include "my.h"

void compute_game(game_t *game)
{
    compute_guis(game->guis, game);
    compute_info(game->window, game->info, game->assets);
}
