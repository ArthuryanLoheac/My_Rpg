/*
** EPITECH PROJECT, 2024
** compute_quest
** File description:
** compute_quest
*/

#include "my.h"

void compute_quest(quest_t *quest, game_t *game)
{
    map_t *map = (map_t *)game->guis->map->ui_content;

    quest->compute(quest, map, game);
}
