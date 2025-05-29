/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

void compute_quest_ui(map_t *map, game_t *game)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(game->window));

    if (map->quest_ui->quest_pos.x > 0) {
        sfSprite_setRotation(map->quest_ui->quest_arrow->sprite,
            get_angle_degree(map->quest_ui->quest_pos,
            sfSprite_getPosition(map->player->sprite->temp->sprite)));
    }
    pos = add(pos, -960, -490);
    sfSprite_setPosition(map->quest_ui->quest_arrow->sprite,
        add(pos, 1850, 20));
}
