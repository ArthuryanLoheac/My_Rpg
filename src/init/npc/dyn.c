/*
** EPITECH PROJECT, 2024
** init_assets()
** File description:
** init_assets()
*/
#include "my.h"

entity_t *init_dyn(sfVector2f pos, assets_t **assets)
{
    entity_t *dyn = malloc(sizeof(entity_t));

    dyn->hidden = false;
    dyn->type = NPC;
    dyn->npc = init_dyn_npc(pos, assets);
    dyn->position = pos;
    dyn->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    dyn->move = true;
    return dyn;
}

npc_t *init_dyn_npc(sfVector2f pos, assets_t **assets)
{
    npc_t *npc = init_npc("Dyn", (sfVector2i){50, 50}, init_image
        (get_asset("Hero_Green", assets), pos, 1),
        FRIENDLY);

    npc->armor = init_item(103, assets);
    npc->ranged = init_item(303, assets);
    npc->melee = init_item(311, assets);
    npc->stats = init_stats2((int[]){8, 8, 8, 8, 8, 8, 8, 8});
    npc->next_pos = NULL;
    sfSprite_setPosition(npc->npc->sprite, pos);
    set_clothes_dyn(assets, npc, npc->armor->id);
    return npc;
}
