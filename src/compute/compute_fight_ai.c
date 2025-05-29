/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

static sfFloatRect get_target_shooter_rect(npc_t *target, npc_t *npc,
    map_t *map)
{
    sfVector2f player_pos = sfSprite_getPosition(npc->npc->sprite);
    sfVector2f target_pos = sfSprite_getPosition(map->player->sprite->temp
        ->sprite);

    if (target)
        player_pos = sfSprite_getPosition(target->npc->sprite);
    return (sfFloatRect){player_pos.x, player_pos.y,
        target_pos.x, target_pos.y};
}

static void atk_ranged(game_t *game, npc_t *target, npc_t *npc)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));
    sfVector2i hits = (sfVector2i){0, 0};

    if (npc->ranged->weapon->magazine.x > 0) {
        hits = compute_ranged_npc_atks(map, npc, target);
        animation_shoot(game, hits, get_target_shooter_rect(target, npc, map),
        npc->ranged->type);
    } else
        npc->ranged->weapon->magazine.x = npc->ranged->weapon->magazine.y;
}

static void atk_melee(game_t *game, npc_t *target, npc_t *npc)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    if (npc->melee)
        compute_melee_npc_atk(map, npc, target);
    else
        compute_unarmd_npc_atk(map, npc, target);
}

static void attack_target(map_t *map, npc_t *target, npc_t *npc, game_t *game)
{
    sfVector2f target_pos = sfSprite_getPosition(map->player->sprite
        ->temp->sprite);
    sfVector2f npc_pos = sfSprite_getPosition(npc->npc->sprite);

    if (target != NULL)
        target_pos = sfSprite_getPosition(target->npc->sprite);
    if (sight_collision(map, target_pos, npc_pos) == true) {
        if (get_distance(target_pos, npc_pos) > 100 && npc->ranged)
            atk_ranged(game, target, npc);
        else
            atk_melee(game, target, npc);
    }
}

static void compute_movement_ai(map_t *map, img_t *img,
    sfVector2f to_move, int *move)
{
    sfSprite *sprite = img->sprite;

    *move = *move - get_len(to_move);
    to_move = sub2(compute_pc_collision(map, add2(to_move,
        sfSprite_getPosition(sprite)), sfSprite_getPosition(sprite)),
        sfSprite_getPosition(sprite));
    if (to_move.x > 0 && to_move.x > abs((int)(to_move.y)))
        img->animate->state = 2;
    if (to_move.x < 0 && abs((int)to_move.x) > abs((int)(to_move.y)))
        img->animate->state = 1;
    if (to_move.y > 0 && to_move.y > abs((int)(to_move.x)))
        img->animate->state = 0;
    if (to_move.y < 0 && abs((int)to_move.y) > abs((int)(to_move.x)))
        img->animate->state = 3;
    if (to_move.x == 0 && to_move.y == 0 && img->animate->state <= 3)
        img->animate->state += 4;
    img->animate->rect.top = img->animate->rect.height * img->animate->state;
    sfSprite_move(sprite, to_move);
    (void) map;
}

static sfVector2f compute_target_pos(map_t *map, npc_t *target)
{
    if (target == NULL)
        return sfSprite_getPosition(map->player->sprite->temp->sprite);
    else
        return sfSprite_getPosition(target->npc->sprite);
}

static bool ai_actions(game_t *game, npc_t *npc,
    sfVector2f target_mov, int *move)
{
    map_t *map = (map_t *)game->guis->map->ui_content;
    npc_t *target = get_index_npc(map->fight->turn_order,
        find_target_ai(map, npc));

    if (get_distance(target_mov, sfSprite_getPosition(npc->npc->sprite)) > 5
        && *move > 0) {
        compute_movement_ai(map, npc->npc, mult3(normalize(sub2(
            target_mov, sfSprite_getPosition(npc->npc->sprite))), 5), move);
    } else {
        if (npc->npc->animate->rect.top <= npc->npc->animate->rect.height * 3)
            npc->npc->animate->rect.top += npc->npc->animate->rect.height * 4;
        attack_target(map, target, npc, game);
        return true;
    }
    return false;
}

static void compute_npc_target_ai(map_t *map, npc_t *npc,
    sfVector2f *target_mov, sfVector2f target_pos)
{
    if (sight_collision(map, target_pos,
        sfSprite_getPosition(npc->npc->sprite)) == false) {
        *target_mov = find_pos_ai(map, target_pos,
            sfSprite_getPosition(npc->npc->sprite));
    } else
        *target_mov = find_ideal_pos_ai(map, target_pos, npc);
}

int compute_npc_fight(map_t *map, game_t *game, npc_t *npc,
    bool is_new)
{
    static int move = 0;
    npc_t *target = get_index_npc(map->fight->turn_order,
        find_target_ai(map, npc));
    sfVector2f target_pos = compute_target_pos(map, target);
    static sfVector2f target_mov;

    map->target_view = sfSprite_getPosition(npc->npc->sprite);
    if (target == NULL)
        target_pos = sfSprite_getPosition(map->player->sprite->temp->sprite);
    else
        target_pos = sfSprite_getPosition(target->npc->sprite);
    if (is_new == true) {
        move = 100 + 100 * npc->stats->MOVE;
        compute_npc_target_ai(map, npc, &target_mov, target_pos);
    } else
        return ai_actions(game, npc, target_mov, &move);
    return false;
}
