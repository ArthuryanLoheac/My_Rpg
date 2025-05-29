/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

void compute_aoe_atk_npc(stats_t *stat, weapon_t *weapon,
    npc_t *target, sfVector2f shooter_pos)
{
    unsigned int to_hit = weapon->bonus_tohit + stat->REF;

    if (difv(weapon, shooter_pos, sfSprite_getPosition(target->npc->sprite))
        < (int)to_hit) {
        compute_ranged_hit_npc(stat, target, weapon);
    }
}

void compute_aoe_atk_pc(stats_t *stat, weapon_t *weapon,
    player_character_t *target, sfVector2f shooter_pos)
{
    unsigned int to_hit = weapon->bonus_tohit + stat->REF;

    if (difv(weapon, shooter_pos, sfSprite_getPosition(target->sprite
        ->temp->sprite)) < (int)to_hit) {
        compute_ranged_hit_pc(stat, target, weapon);
    }
}

//Add the d10 to REF BEFORE and remove it after, thx
void compute_aoe_target(stats_t *stat, weapon_t *weapon,
    entity_t *entity, sfVector2f shooter_pos)
{
    if (entity->type == NPC) {
        compute_aoe_atk_npc(stat, weapon, entity->npc, shooter_pos);
    }
    if (entity->type == PC) {
        compute_aoe_atk_pc(stat, weapon, entity->pc, shooter_pos);
    }
}
