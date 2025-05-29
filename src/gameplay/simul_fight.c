/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

int d10(sfSprite *sprite, game_t *game, int i)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));
    int res = (int)roll_dice_10(1);

    my_insert_front_list(&map->dice, init_dice(game,
        add(sfSprite_getPosition(sprite), 0, i * 96), res));
    return res;
}

int difv(weapon_t *wpn, sfVector2f p1, sfVector2f p2)
{
    return (int)simulate_dv(wpn, 0.02 * get_distance(p1, p2));
}

int difs(weapon_t *wpn, sfSprite *sprite1, sfSprite *sprite2)
{
    return difv(wpn, sfSprite_getPosition(sprite1),
        sfSprite_getPosition(sprite2));
}

static sfVector2i compute_ranged_player_atk_npc(map_t *map, npc_t *npc,
    game_t *game)
{
    weapon_t *wpn = map->inventory->inventory->main_slots[12]->items->weapon;
    int hits = 0;

    wpn->durability.x = MAX(wpn->durability.x - 10 + map->player->stats
        ->TECH, 0);
    for (int i = 0; i < wpn->rof; i++) {
        if (difs(wpn, map->player->sprite->temp->sprite, npc->npc->sprite) <
            wpn->bonus_tohit + d10(map->player->sprite->temp->sprite, game, i)
            + (int)map->player->stats->REF && wpn->magazine.x > 0 &&
            wpn->durability.x >= 0) {
            compute_ranged_hit_npc(map->player->stats, npc, wpn);
            hits++;
        }
        if (wpn->magazine.x <= 0)
            return empty_weapon(hits, game);
        wpn->magazine.x--;
    }
    map->fight->fired = true;
    return (sfVector2i){hits, wpn->rof};
}

static void compte_rafale_sounds(game_t *game, weapon_t *wpn)
{
    if (wpn->type == RIFLE) {
        sfSound_stop(game->sounds->assault_rifle_rafale->sound);
        sfSound_play(game->sounds->assault_rifle_rafale->sound);
    }
    if (wpn->type == SMG) {
        sfSound_stop(game->sounds->smg_rafale->sound);
        sfSound_play(game->sounds->smg_rafale->sound);
    }
}

static sfVector2i compute_ranged_autofire_player_atk_npc(map_t *map,
    npc_t *npc, game_t *game)
{
    weapon_t *wpn = map->inventory->inventory->main_slots[12]->items->weapon;
    int to_hit;
    int hits = 0;

    wpn->durability.x = MAX(wpn->durability.x - 100 + 10 *
        (int)map->player->stats->TECH, 0);
    if (wpn->magazine.x < 10)
        return empty_weapon(hits, game);
    compte_rafale_sounds(game, wpn);
    wpn->magazine.x -= 10;
    to_hit = wpn->bonus_tohit + d10(map->player->sprite->temp->sprite, game,
        0) + map->player->stats->REF - 3 - difs(wpn, map->player->sprite->temp
        ->sprite, npc->npc->sprite);
    if (to_hit > 0) {
        compute_ranged_autofire_hit_npc(map->player->stats, npc, wpn, to_hit);
        hits += 10;
    }
    map->fight->fired = true;
    return (sfVector2i){hits, 10};
}

static bool melee_reach(unsigned int to_hit, game_t *game, npc_t *npc, int i)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    if (get_distance(sfSprite_getPosition(map->player->sprite->temp
            ->sprite), sfSprite_getPosition(npc->npc->sprite)) < 100 && npc
            ->stats->DEX + d10(map->player->sprite->temp->sprite, game, i) <
            to_hit)
        return true;
    return false;
}

static sfVector2i compute_melee_player_atk_npc(game_t *game, npc_t *npc)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));
    weapon_t *weapon = map->inventory->inventory->main_slots[12]->items
        ->weapon;
    unsigned int to_hit;
    int hits = 0;

    for (int i = 0; i < weapon->rof; i++) {
        weapon->durability.x = MAX(weapon->durability.x - 10 + (int)map->player
            ->stats->TECH, 0);
        to_hit = weapon->bonus_tohit + roll_dice_10(1) +
            map->player->stats->DEX;
        if (melee_reach(to_hit, game, npc, i) && weapon->durability.x >= 0) {
            compute_melee_hit_npc(map->player->stats, npc, weapon);
            sfSound_stop(game->sounds->melee->sound);
            sfSound_play(game->sounds->melee->sound);
            hits++;
        }
    }
    map->fight->fired = true;
    return (sfVector2i){hits - hits, weapon->rof - weapon->rof};
}

static sfVector2i compute_unarmed_player_atk_npc(game_t *game, npc_t *npc)
{
    unsigned int to_hit;
    int hits = 0;
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    for (int i = 0; i < 2; i++) {
        to_hit = roll_dice_10(1) + map->player->stats->DEX;
        if (melee_reach(to_hit, game, npc, i)) {
            compute_unarmd_hit_npc(map->player->stats, npc);
            hits++;
        }
    }
    map->fight->fired = true;
    return (sfVector2i){hits - hits, 2 - 2};
}

sfVector2i compute_player_atk_npc(map_t *map, npc_t *npc, fight_t *fight,
    game_t *game)
{
    weapon_t *wpn;

    if (map->inventory->inventory->main_slots[12]->items == NULL)
        return compute_unarmed_player_atk_npc(game, npc);
    wpn = map->inventory->inventory->main_slots[12]->items->weapon;
    if ((wpn->type == SMG || wpn->type == RIFLE) && fight->gui->mode == 1)
        return compute_ranged_autofire_player_atk_npc(map, npc, game);
    if ((wpn->type <= 6 || wpn->type == BOW) && wpn->type != SHOTGUN)
        return compute_ranged_player_atk_npc(map, npc, game);
    if (wpn->type >= 10)
        return compute_melee_player_atk_npc(game, npc);
    if (wpn->type == SHOTGUN)
        return compute_shell(game, wpn, fight->gui->aoe_shotgun,
        sfSprite_getPosition(map->player->sprite->temp->sprite));
    if (wpn->type == NADL || wpn->type == ROCKET_L)
        return compute_expl(game, wpn, fight->gui->aoe, sfSprite_getPosition(
            map->player->sprite->temp->sprite));
    return (sfVector2i){0, 0};
}
