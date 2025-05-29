/*
** EPITECH PROJECT, 2024
** destroy_player
** File description:
** destroy_player
*/

#include "my.h"

void destroy_stats(stats_t *stats)
{
    free(stats);
}

void destroy_player(player_character_t *player)
{
    destroy_stats(player->stats);
    free(player);
}
