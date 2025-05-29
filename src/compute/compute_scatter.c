/*
** EPITECH PROJECT, 2024
** compute_scatter
** File description:
** compute_scatter
*/

#include "my.h"

void compute_scatter(game_t *game, entity_t *entity)
{
    map_t *map = (map_t *)game->guis->map->ui_content;
    sfFloatRect rect1 = sfSprite_getGlobalBounds(map
        ->player->sprite->temp->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(entity
        ->scatter->scatter->sprite);

    if ((entity->scatter->interact == false || sfKeyboard_isKeyPressed(game
        ->keybinds->interact) == sfTrue) && entity->scatter->init_new != NULL
        && entity->hidden == false &&
        sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue) {
        entity->scatter->init_new(game, map);
    }
}
