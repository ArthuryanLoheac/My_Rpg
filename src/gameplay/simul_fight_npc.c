/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

static void atk_ranged(map_t *map, npc_t *npc, npc_t *target, weapon_t *weapon)
{
    if (target != NULL)
        compute_ranged_hit_npc(npc->stats, target, weapon);
    else
        compute_ranged_hit_pc(npc->stats, map->player, weapon);
}

static void atk_melee(map_t *map, npc_t *npc, npc_t *target, weapon_t *weapon)
{
    if (target != NULL)
        compute_melee_hit_npc(npc->stats, target, weapon);
    else
        compute_melee_hit_pc(npc->stats, map->player, weapon);
}

static void atk_unarmd(map_t *map, npc_t *npc, npc_t *target)
{
    if (target != NULL)
        compute_unarmd_hit_npc(npc->stats, target);
    else
        compute_unarmd_hit_pc(npc->stats, map->player);
}

static sfVector2i compute_ranged_npc_atk(map_t *map, npc_t *npc, npc_t *target)
{
    weapon_t *wpn = npc->ranged->weapon;
    int to_hit = 0;
    sfVector2f t_pos = sfSprite_getPosition(map->player->sprite->temp->sprite);
    int hits = 0;

    if (target)
        t_pos = sfSprite_getPosition(target->npc->sprite);
    if (!target && map->fight->action == DODGE)
        to_hit -= map->player->stats->DEX / 2;
    wpn->durability.x = MAX(wpn->durability.x - 10 + (int)npc->stats->TECH, 0);
    wpn->magazine.x--;
    for (int i = 0; i < wpn->rof; i++) {
        to_hit += wpn->bonus_tohit + roll_dice_10(1) + npc->stats->REF;
        if ((int)difv(wpn, sfSprite_getPosition(npc->npc->sprite), t_pos)
            < to_hit && wpn->magazine.x > 0) {
            atk_ranged(map, npc, target, wpn);
            hits++;
        }
    }
    return (sfVector2i){hits, wpn->rof};
}

sfVector2i compute_ranged_npc_atks(map_t *map, npc_t *npc, npc_t *target)
{
    weapon_t *weapon = npc->ranged->weapon;

    if ((weapon->type <= 6 || weapon->type == BOW) && weapon->type != SHOTGUN)
        return compute_ranged_npc_atk(map, npc, target);
    return (sfVector2i){0, 0};
}

void compute_melee_npc_atk(map_t *map, npc_t *npc, npc_t *target)
{
    weapon_t *weapon = npc->melee->weapon;
    int to_hit = 0;
    int dex = map->player->stats->DEX;

    if (target)
        dex = target->stats->DEX;
    if (!target && map->fight->action == DODGE)
        to_hit -= map->player->stats->DEX / 2;
    weapon->durability.x = MAX(weapon->durability.x - 10 + npc->stats
        ->TECH, 0);
    if (weapon->durability.x < 0)
            weapon->durability.x = 0;
    for (int i = 0; i < weapon->rof; i++) {
        to_hit += weapon->bonus_tohit + roll_dice_10(1) + npc->stats->DEX;
        if (dex + (int)roll_dice_10(1) < to_hit) {
            atk_melee(map, npc, target, weapon);
        }
    }
}

void compute_unarmd_npc_atk(map_t *map, npc_t *npc, npc_t *target)
{
    int to_hit = 0;
    int dex = map->player->stats->DEX;

    if (target)
        dex = target->stats->DEX;
    if (!target && map->fight->action == DODGE)
        to_hit -= map->player->stats->DEX / 2;
    for (int i = 0; i < 2; i++) {
        to_hit += roll_dice_10(1) + npc->stats->DEX;
        if (dex + (int)roll_dice_10(1) < to_hit) {
            atk_unarmd(map, npc, target);
        }
    }
}
