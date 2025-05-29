/*
** EPITECH PROJECT, 2024
** init_assets()
** File description:
** init_assets()
*/
#include "my.h"

static int get_id_bad_item(void)
{
    int random_cat = (rand() % 15) + 1;
    int added_nbr = 0;

    if (random_cat == 2)
        added_nbr = (rand() % 5) + 1;
    if (random_cat == 1)
        added_nbr = (rand() % 2) + 1;
    if (random_cat == 3)
        added_nbr = 1;
    if (random_cat < 4)
        return ((random_cat * 100) + added_nbr);
    else
        return -1;
}

entity_t *init_mook(sfVector2f pos, assets_t **assets, char *name, int hp)
{
    entity_t *mook = malloc(sizeof(entity_t));
    int choose_bad_item = get_id_bad_item();

    mook->hidden = false;
    mook->type = NPC;
    mook->npc = init_mook_npc(pos, assets, name, hp);
    mook->position = pos;
    mook->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    mook->move = true;
    mook->npc->ranged = init_item(301, assets);
    mook->npc->melee = init_item(310, assets);
    mook->npc->ranged->weapon->bonus_tohit += 2;
    mook->npc->stats->REF += 2;
    if (choose_bad_item != -1)
        mook->npc->loot_1 = init_item(choose_bad_item, assets);
    else
        mook->npc->loot_1 = NULL;
    mook->npc->loot_2 = NULL;
    return mook;
}

npc_t *init_mook_npc(sfVector2f pos, assets_t **assets, char *name, int hp)
{
    npc_t *npc = init_npc(name, (sfVector2i){hp, hp}, init_image
        (get_asset("Hero_Red", assets), pos, 1), HOSTILE);

    if (my_strcmp(name, "Mook1") == 0)
        npc->melee = init_item(310, assets);
    npc->ranged = NULL;
    npc->armor = init_item(101, assets);
    npc->loot_1 = init_item(201, assets);
    npc->loot_2 = NULL;
    npc->stats = init_stats2((int[]){4 + rand() % 3, 4 + rand() % 3, 4 +
        rand() % 3, 4 + rand() % 3, 4 + rand() % 3, 4 + rand() % 3, 4 +
        rand() % 3, 4 + rand() % 3});
    sfSprite_setPosition(npc->npc->sprite, pos);
    set_clothes_npc(assets, npc, 101);
    return npc;
}
