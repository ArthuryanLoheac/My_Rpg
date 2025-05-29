/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

static bool is_closest_npc(npc_t *npc, linked_list_t *ll, int min,
    enum npc_type_e enemy)
{
    if (((entity_t *)(ll->data))->type == NPC && ((entity_t *)(ll->data))->npc
        ->type == enemy && get_distance(sfSprite_getPosition(npc->npc
        ->sprite), sfSprite_getPosition(((entity_t *)(ll->data))->npc->npc
        ->sprite)) < min)
        return true;
    return false;
}

static bool is_closest_pc(npc_t *npc, linked_list_t *ll, int min)
{
    if (((entity_t *)(ll->data))->type == PC && get_distance(
        sfSprite_getPosition(npc->npc->sprite), sfSprite_getPosition(
        ((entity_t *)(ll->data))->pc->sprite->temp->sprite)) < min)
        return true;
    return false;
}

static int get_npc_min(npc_t *npc, linked_list_t *ll)
{
    return get_distance(sfSprite_getPosition(npc->npc->sprite),
        sfSprite_getPosition(((entity_t *)(ll->data))->npc->npc->sprite));
}

static int get_pc_min(npc_t *npc, linked_list_t *ll)
{
    return get_distance(sfSprite_getPosition(npc->npc->sprite),
        sfSprite_getPosition(((entity_t *)(ll->data))->pc->sprite->temp
        ->sprite));
}

int find_target_ai(map_t *map, npc_t *npc)
{
    int min = 99999999;
    int min_index = -1;
    linked_list_t *ll = map->fight->turn_order;
    enum npc_type_e enemy = FRIENDLY;

    if (npc->type == FRIENDLY)
        enemy = HOSTILE;
    for (int i = 0; ll; i++) {
        if (is_closest_npc(npc, ll, min, enemy)) {
            min = get_npc_min(npc, ll);
            min_index = i;
        }
        if (is_closest_pc(npc, ll, min) && enemy == FRIENDLY) {
            min = get_pc_min(npc, ll);
            min_index = i;
        }
        ll = ll->next;
    }
    return min_index;
}
