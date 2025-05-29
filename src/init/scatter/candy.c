/*
** EPITECH PROJECT, 2024
** init_candy()
** File description:
** init_candy()
*/

#include "my.h"

void quest_increase2(game_t *game, map_t *map)
{
    game->quests->prog.x += 2;
    get_scatter(4, map->entity_all)->hidden = true;
    get_scatter(4, map->entity_all)->scatter->init_new = NULL;
    map->dialogue = diag(game->quests->prefix, "memories/candy");
    (void) map;
}

entity_t *init_candy(sfVector2f pos, assets_t **assets)
{
    entity_t *candy = malloc(sizeof(entity_t));

    candy->hidden = true;
    candy->type = SCATTER;
    candy->scatter = init_candy_scatter(pos, assets);
    candy->position = pos;
    candy->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    candy->move = false;
    return candy;
}

scatter_t *init_candy_scatter(sfVector2f pos, assets_t **assets)
{
    scatter_t *candy = malloc(sizeof(scatter_t));

    candy->scatter = init_image(get_asset("candy", assets), pos, 1.28);
    candy->init_new = &quest_increase2;
    candy->interact = true;
    candy->id = 4;
    candy->map = my_strdup("QueenHouse/");
    return candy;
}
