/*
** EPITECH PROJECT, 2024
** init_assets()
** File description:
** init_assets()
*/
#include "my.h"


static void init_animated_npc(npc_t *npc)
{
    init_animated_img(npc->npc, 96, 96, vect0());
    set_animate_image(npc->npc, 4, 1, 4);
    npc->npc->animate->animation_time = (rand() % 10) / 100.0 + 0.2;
    npc->npc->animate->rect.top = npc->npc->animate->rect.height * 4;
}

static void loot_null(npc_t *npc)
{
    npc->armor = NULL;
    npc->loot_1 = NULL;
    npc->loot_2 = NULL;
    npc->ranged = NULL;
    npc->melee = NULL;
}

npc_t *init_npc(char *name, sfVector2i hp, img_t *img, enum npc_type_e type)
{
    npc_t *npc = malloc(sizeof(npc_t));

    npc->map = my_strdup("Night_City/");
    npc->in_combat = sfFalse;
    npc->hp = hp;
    npc->name = my_strdup(name);
    npc->type = type;
    npc->npc = img;
    loot_null(npc);
    npc->next_pos = NULL;
    npc->own_clock = init_time();
    npc->clothes = NULL;
    npc->talkable = NO_TL;
    init_animated_npc(npc);
    sfSprite_setOrigin(npc->npc->sprite, (sfVector2f){
    npc->npc->animate->rect.width / 2, npc->npc->animate->rect.height / 2});
    return npc;
}

static void random_hair_npc(assets_t **assets, npc_t *npc)
{
    int hair = rand() % (19 + 1) + 1;
    int cap = rand() % 10;
    char str[20];

    if (hair <= 19) {
        sprintf(str, "Hair_%d", hair);
        add_clothe_npc(assets, &npc->clothes, str, npc);
    }
    if (cap == 1) {
        cap = rand() % 5 + 1;
        sprintf(str, "Cap_%d", cap);
        add_clothe_npc(assets, &npc->clothes, str, npc);
    }
}

static void init_armor_npc(assets_t **assets, npc_t *npc, int armor)
{
    if (armor == 101)
        add_clothe_npc(assets, &npc->clothes, "Leather_Armor", npc);
    if (armor == 102)
        add_clothe_npc(assets, &npc->clothes, "Kevlar_Armor", npc);
    if (armor == 103)
        add_clothe_npc(assets, &npc->clothes, "Light_Armorjack", npc);
    if (armor == 104)
        add_clothe_npc(assets, &npc->clothes, "Medium_Armorjack", npc);
    if (armor == 105)
        add_clothe_npc(assets, &npc->clothes, "Heavy_Armorjack", npc);
    if (armor == 106)
        add_clothe_npc(assets, &npc->clothes, "Flak_Armor", npc);
    if (armor == 107)
        add_clothe_npc(assets, &npc->clothes, "Metalgear_Armor", npc);
}

void set_clothes_npc(assets_t **assets, npc_t *npc, int armor)
{
    int pant = rand() % 2;

    add_clothe_npc(assets, &npc->clothes, "Shoes", npc);
    if (pant == 0)
        add_clothe_npc(assets, &npc->clothes, "Pant_1", npc);
    if (pant == 1)
        add_clothe_npc(assets, &npc->clothes, "Pant_1_w", npc);
    add_clothe_npc(assets, &npc->clothes, "Shirt_Npc", npc);
    init_armor_npc(assets, npc, armor);
    random_hair_npc(assets, npc);
}

void set_clothes_cryspi(assets_t **assets, npc_t *npc, int armor)
{
    add_clothe_npc(assets, &npc->clothes, "Shoes", npc);
    add_clothe_npc(assets, &npc->clothes, "Pant_1", npc);
    add_clothe_npc(assets, &npc->clothes, "Shirt_1", npc);
    add_clothe_npc(assets, &npc->clothes, "Hair_11", npc);
    init_armor_npc(assets, npc, armor);
}

void set_clothes_dyn(assets_t **assets, npc_t *npc, int armor)
{
    add_clothe_npc(assets, &npc->clothes, "Shoes", npc);
    add_clothe_npc(assets, &npc->clothes, "Pant_1", npc);
    add_clothe_npc(assets, &npc->clothes, "Shirt_Npc", npc);
    init_armor_npc(assets, npc, armor);
}
