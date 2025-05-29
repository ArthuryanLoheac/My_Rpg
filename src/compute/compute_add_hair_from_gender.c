/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** compute_add_hair_from_gender
*/

#include "my.h"

void compute_add_hair_from_gender(int gender,
    game_t *game, player_character_t *player)
{
    if (gender == 1)
        add_clothe(game->assets, &player->sprite->clothes,
            "Hair_b", sfSprite_getPosition(player->sprite->temp->sprite));
    if (gender == 2)
        add_clothe(game->assets, &player->sprite->clothes,
            "Hair_g", sfSprite_getPosition(player->sprite->temp->sprite));
}
