/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

static void compute_shell_atk(map_t *map, weapon_t *weapon,
    sfRectangleShape *target, sfVector2f shooter_pos)
{
    linked_list_t *ll;
    entity_t *entity;

    weapon->durability.x = MAX(weapon->durability.x - 10 + map->player->stats
        ->TECH, 0);
    if (weapon->durability.x < 0)
            weapon->durability.x = 0;
    weapon->magazine.x--;
    ll = map->fight->turn_order;
    while (ll != NULL) {
        entity = ((entity_t *)(ll->data));
        if (point_in_rectangle(target, entity->position) == sfTrue &&
            entity->type == NPC)
            compute_aoe_target(map->player->stats, weapon, entity,
            shooter_pos);
        ll = ll->next;
    }
}

sfVector2i compute_shell(game_t *game, weapon_t *weapon,
    sfRectangleShape *target, sfVector2f shooter_pos)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));
    unsigned int ref = map->player->stats->REF;
    int hits = 0;

    for (int i = 0; i < weapon->rof; i++) {
        map->player->stats->REF = ref + d10(map->player->sprite->temp->sprite,
            game, i);
        if (weapon->magazine.x >= 1 && weapon->durability.x >= 0) {
            fprintf(stderr, "attack %d, magazine is %u\n", i,
                weapon->magazine.x);
                compute_shell_atk(map, weapon, target, shooter_pos);
                hits++;
        }
        map->player->stats->REF = ref;
        if (weapon->magazine.x <= 0)
            return empty_weapon(hits, game);
    }
    map->fight->fired = true;
    return (sfVector2i){hits, weapon->rof * 10};
}

static void compute_expl_atk(map_t *map, weapon_t *weapon,
    sfCircleShape *target, sfVector2f shooter_pos)
{
    linked_list_t *ll;
    entity_t *entity;

    weapon->durability.x = MAX(weapon->durability.x - 10 + map->player->stats
        ->TECH, 0);
    if (weapon->durability.x < 0)
        weapon->durability.x = 0;
    weapon->magazine.x--;
    ll = map->fight->turn_order;
    while (ll != NULL) {
    entity = ((entity_t *)(ll->data));
    if (get_distance(sfCircleShape_getPosition(target), entity->position) <=
        300)
        compute_aoe_target(map->player->stats, weapon, entity, shooter_pos);
    ll = ll->next;
    }
}

sfVector2i compute_expl(game_t *game, weapon_t *weapon, sfCircleShape *target,
    sfVector2f shooter_pos)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));
    unsigned int ref = map->player->stats->REF;
    int hits = 0;

    for (int i = 0; i < weapon->rof; i++) {
        map->player->stats->REF = ref + d10(map->player->sprite->temp->sprite,
            game, i);
        if (weapon->magazine.x >= 1 && weapon->durability.x >= 0
            && weapon->durability.x >= 0) {
            compute_expl_atk(map, weapon, target, shooter_pos);
            hits++;
        }
        map->player->stats->REF = ref;
        if (weapon->magazine.x <= 0)
            return empty_weapon(hits, game);
    }
    map->fight->fired = true;
    return (sfVector2i){hits, weapon->rof};
}
