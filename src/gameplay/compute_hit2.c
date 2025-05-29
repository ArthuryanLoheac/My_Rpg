/*
** EPITECH PROJECT, 2023
** simulate_fight.c
** File description:
** function that simulates fight between 2 entities
*/

#include "my.h"

void compute_unarmd_hit_pc(stats_t *stats, player_character_t *pc)
{
    unsigned int dmg;
    item_t *armor = pc->inventory->main_slots[8]->items;

    dmg = roll_dice_6((int)stats->BODY / 2);
    if ((rand() % 101) <= (int)stats->LUCK * 2)
        dmg *= 2;
    if (armor != NULL) {
        pc->hp->x = MAX(pc->hp->x - MAX((int)dmg - (armor->armor->sp.x / 2),
            0), 0);
        if ((int)dmg > armor->armor->sp.x / 2 && armor->armor->sp.x > 0)
            armor->armor->sp.x--;
    } else
        pc->hp->x = MAX(pc->hp->x - dmg, 0);
}

void compute_unarmd_hit_npc(stats_t *stats, npc_t *npc)
{
    unsigned int dmg;

    dmg = roll_dice_6((int)stats->BODY / 2);
    if ((rand() % 101) <= (int)stats->LUCK * 2)
        dmg *= 2;
    npc->hp.x -= MAX((int)dmg - (npc->armor->armor->sp.x / 2), 0);
    if ((int)dmg > npc->armor->armor->sp.x / 2 && npc->armor->armor->sp.x > 0)
        npc->armor->armor->sp.x--;
    if (npc->hp.x < 0)
        npc->hp.x = 0;
}
