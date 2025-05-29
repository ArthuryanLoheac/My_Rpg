/*
** EPITECH PROJECT, 2024
** init_map
** File description:
** init_map
*/

#include "my.h"

quest_ui_t *init_quest_ui(game_t *game)
{
    quest_ui_t *quest_ui = malloc(sizeof(quest_ui_t));

    quest_ui->quest_pos = (sfVector2f){-1, -1};
    quest_ui->quest_arrow = init_image(get_asset("Arrow", game->assets),
        vect0(), 1);
    sfSprite_setOrigin(quest_ui->quest_arrow->sprite, (sfVector2f){64, 64});
    return quest_ui;
}
