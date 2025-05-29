/*
** EPITECH PROJECT, 2023
** simulate_fight.c
** File description:
** function that simulates fight between 2 entities
*/

#include "my.h"

void compute_ranged_autofire_hit_npc(stats_t *stat, npc_t *npc,
    weapon_t *weapon, int diff)
{
    unsigned int dmg;

    dmg = roll_dice_6(2) * diff;
    dmg += weapon->bonus_damage;
    if ((rand() % 101) <= (int)stat->LUCK * 2)
        dmg *= 2;
    if (npc->armor != NULL) {
        npc->hp.x = MAX(npc->hp.x - MAX(dmg - npc->armor->armor->sp.x, 0), 0);
        if (npc->hp.x < 0)
            npc->hp.x = 0;
        if ((int)dmg > npc->armor->armor->sp.x && npc->armor->armor->sp.x > 0)
            npc->armor->armor->sp.x--;
    } else
    npc->hp.x = MAX(npc->hp.x - (int) dmg, 0);
    if (npc->hp.x < 0)
        npc->hp.x = 0;
}

void compute_ranged_hit_npc(stats_t *stat, npc_t *npc,
    weapon_t *weapon)
{
    unsigned int dmg;

    dmg = roll_dice_6(weapon->damagd6);
    dmg += weapon->bonus_damage;
    if ((rand() % 101) <= (int)stat->LUCK * 2)
        dmg *= 2;
    if (npc->armor != NULL) {
        npc->hp.x = MAX(npc->hp.x - MAX(dmg - npc->armor->armor->sp.x, 0), 0);
        if (npc->hp.x < 0)
            npc->hp.x = 0;
        if ((int)dmg > npc->armor->armor->sp.x && npc->armor->armor->sp.x > 0)
            npc->armor->armor->sp.x--;
    } else
        npc->hp.x = MAX(npc->hp.x - (int) dmg, 0);
    if (npc->hp.x < 0)
        npc->hp.x = 0;
}

void compute_ranged_hit_pc(stats_t *stat, player_character_t *pc,
    weapon_t *weapon)
{
    unsigned int dmg;
    item_t *armor = pc->inventory->main_slots[8]->items;

    dmg = roll_dice_6(weapon->damagd6);
    dmg += weapon->bonus_damage;
    if ((rand() % 101) <= (int)stat->LUCK * 2)
        dmg *= 2;
    if (armor != NULL) {
        pc->hp->x = MAX(pc->hp->x - MAX((int)dmg - armor->armor->sp.x,
            0), 0);
        if ((int)dmg > armor->armor->sp.x && armor->armor->sp.x > 0)
            armor->armor->sp.x--;
    } else
        pc->hp->x = MAX(pc->hp->x - dmg, 0);
}

void compute_melee_hit_pc(stats_t *stat, player_character_t *pc,
    weapon_t *weapon)
{
    unsigned int dmg;
    item_t *armor = pc->inventory->main_slots[8]->items;

    dmg = roll_dice_6(weapon->damagd6);
    dmg += weapon->bonus_damage;
    if ((rand() % 101) <= (int)stat->LUCK * 2)
        dmg *= 2;
    if (armor != NULL) {
        pc->hp->x = MAX(pc->hp->x - MAX((int)dmg - (armor->armor->sp.x / 2),
            0), 0);
        if ((int)dmg > armor->armor->sp.x / 2 && armor->armor->sp.x > 0)
            armor->armor->sp.x--;
    } else
        pc->hp->x = MAX(pc->hp->x - dmg, 0);
}

void compute_melee_hit_npc(stats_t *stats, npc_t *npc,
    weapon_t *weapon)
{
    unsigned int dmg;

    dmg = roll_dice_6(weapon->damagd6);
    dmg += weapon->bonus_damage;
    if ((rand() % 101) <= (int)stats->LUCK * 2)
        dmg *= 2;
    if (npc->armor != NULL) {
        npc->hp.x -= MAX((int)dmg - (npc->armor->armor->sp.x / 2), 0);
        if ((int)dmg > npc->armor->armor->sp.x / 2 && npc->armor->armor->sp.x
            > 0)
            npc->armor->armor->sp.x--;
    } else
        npc->hp.x = MAX(npc->hp.x - (int)dmg, 0);
    if (npc->hp.x < 0)
        npc->hp.x = 0;
}
