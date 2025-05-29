/*
** EPITECH PROJECT, 2024
** init_assets()
** File description:
** init_assets()
*/
#include "my.h"

entity_t *init_cryspi(sfVector2f pos, assets_t **assets)
{
    entity_t *cryspi = malloc(sizeof(entity_t));

    cryspi->hidden = false;
    cryspi->type = NPC;
    cryspi->npc = init_cryspi_npc(pos, assets);
    cryspi->position = pos;
    cryspi->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    cryspi->move = true;
    return cryspi;
}

npc_t *init_cryspi_npc(sfVector2f pos, assets_t **assets)
{
    npc_t *npc = init_npc("Cryspi", (sfVector2i){35, 35}, init_image
        (get_asset("Hero_Green", assets), pos, 1), FRIENDLY);

    npc->armor = init_item(103, assets);
    npc->ranged = init_item(301, assets);
    npc->melee = init_item(310, assets);
    npc->stats = init_stats2((int[]){8, 8, 8, 8, 8, 8, 8, 8});
    sfSprite_setPosition(npc->npc->sprite, pos);
    set_clothes_cryspi(assets, npc, npc->armor->id);
    return npc;
}
