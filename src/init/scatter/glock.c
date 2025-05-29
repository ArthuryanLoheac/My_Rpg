/*
** EPITECH PROJECT, 2024
** init_glock()
** File description:
** init_glock()
*/
#include "my.h"

void quest_increase1(game_t *game, map_t *map)
{
    game->quests->prog.x++;
    get_scatter(2, map->entity_all)->hidden = true;
    get_scatter(2, map->entity_all)->scatter->init_new = NULL;
    map->dialogue = diag(game->quests->prefix, "memories/glock");
    (void) map;
}

entity_t *init_glock(sfVector2f pos, assets_t **assets)
{
    entity_t *glock = malloc(sizeof(entity_t));

    glock->hidden = true;
    glock->type = SCATTER;
    glock->scatter = init_glock_scatter(pos, assets);
    glock->position = pos;
    glock->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    glock->move = false;
    return glock;
}

scatter_t *init_glock_scatter(sfVector2f pos, assets_t **assets)
{
    scatter_t *glock = malloc(sizeof(scatter_t));

    glock->scatter = init_image(get_asset("glock", assets), pos, 1.28);
    glock->init_new = &quest_increase1;
    glock->interact = true;
    glock->id = 2;
    glock->map = my_strdup("QueenHouse/");
    return glock;
}
