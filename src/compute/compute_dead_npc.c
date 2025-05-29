/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"


static void drop_loot_npc_second(npc_t **n, map_t **map)
{
    sfVector2f pos_drop = sfSprite_getPosition((*n)->npc->sprite);

    if ((*n)->ranged) {
        drop_item_with_item(&(*map)->entity_all, &(*map),
            (sfVector2f){pos_drop.x + (rand() % 128 - 64),
            pos_drop.y + (rand() % 128 - 64)}, (*n)->ranged);
        (*n)->ranged = NULL;
    }
    if ((*n)->melee) {
        drop_item_with_item(&(*map)->entity_all, &(*map),
            (sfVector2f){pos_drop.x + (rand() % 128 - 64),
            pos_drop.y + (rand() % 128 - 64)}, (*n)->melee);
        (*n)->melee = NULL;
    }
}

static void drop_loot_npc(npc_t *n, map_t *map)
{
    sfVector2f pos_drop = sfSprite_getPosition(n->npc->sprite);

    drop_loot_npc_second(&n, &map);
    if (n->loot_1) {
        drop_item_with_item(&map->entity_all, &map,
            (sfVector2f){pos_drop.x, pos_drop.y + 64}, n->loot_1);
        n->loot_1 = NULL;
    }
    if (n->loot_2) {
        drop_item_with_item(&map->entity_all, &map,
            (sfVector2f){pos_drop.x, pos_drop.y + 64}, n->loot_2);
        n->loot_1 = NULL;
    }
}

void npc_death(game_t *game, map_t *map)
{
    npc_t *n = get_index_npc(map->fight->turn_order, map->fight->fighter);

    sfTexture_destroy(n->npc->texture);
    n->npc->texture = sfTexture_createFromFile(get_asset("Hero_Ded",
        game->assets), NULL);
    map->player->xp_data->xp_player.x += n->stats->BODY + n->stats->DEX +
        n->stats->EMP + n->stats->HUM + n->stats->LUCK + n->stats->MOVE +
        n->stats->REF + n->stats->TECH + n->stats->WILL;
    sfSprite_setTexture(n->npc->sprite, n->npc->texture, sfFalse);
    my_delete_nodes2(&map->fight->turn_order, map->fight->fighter);
    if (map->fight->fighter >= my_list_size(map->fight->turn_order))
        map->fight->fighter = 0;
    if (count_hostile(map->fight->turn_order) == 0)
        end_fight(game, map);
    drop_loot_npc(n, map);
    return;
}
