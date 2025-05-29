/*
** EPITECH PROJECT, 2024
** use items
** File description:
** use_drugs
*/

#include "my.h"

static main_slots_t *get_items_pos(game_t *game, map_t *map)
{
    sfFloatRect rec_rect = {1, 1, 1, 1};
    sfVector2f mouse_pos = get_mouse_pos(game->window);

    for (int i = 0; i < 20; i++) {
        if (!map->inventory->inventory->
            main_slots[i] || !map->inventory->inventory->
            main_slots[i]->items)
            continue;
        rec_rect = sfSprite_getGlobalBounds(map->inventory->inventory->
            main_slots[i]->items->icon->sprite);
        if (sfFloatRect_contains(&rec_rect, mouse_pos.x, mouse_pos.y)
            == sfTrue) {
            return map->inventory->inventory->
                main_slots[i];
        }
    }
    return NULL;
}

static void check_no_poison(main_slots_t *item, player_character_t *pc)
{
    if ((item->items)->drug->effect == NO_POISON) {
        pc->hp->x += (pc->stats->BODY + pc->stats->WILL) / 2;
        if (pc->hp->x > pc->hp->y)
            pc->hp->x = pc->hp->y;
        (item->items)->drug->uses.x = (item->items)->drug->uses.x - 1;
        if ((item->items)->drug->uses.x == 0) {
            destroy_item((item->items));
            item->items = NULL;
        }
        return;
    }
}

static void use_item_drugs(main_slots_t *item, player_character_t *pc)
{
    if (!(item) || !(item->items) || (item->items)->type != DRUGS)
        return;
    if ((item->items)->drug->effect == BODY_WILL_HEAL) {
        pc->hp->x += pc->stats->BODY + pc->stats->WILL;
        if (pc->hp->x > pc->hp->y)
            pc->hp->x = pc->hp->y;
        (item->items)->drug->uses.x = (item->items)->drug->uses.x - 1;
        if ((item->items)->drug->uses.x == 0) {
            destroy_item((item->items));
            item->items = NULL;
        }
        return;
    }
    check_no_poison(item, pc);
}

void check_use_items(map_t *map, game_t *game, bool *is_picked)
{
    main_slots_t *items = NULL;

    if ((game->events->type == sfEvtMouseButtonReleased && game->events->
        mouseButton.button == sfMouseRight) &&
        ((map->fight->action_taken == false)
        || map->fight->is_fight == false)) {
        map->fight->action_taken = map->fight->is_fight == true ? true :
            map->fight->action_taken;
        if (*is_picked == false && map->inventory->items_slots_picked == -1) {
            items = get_items_pos(game, map);
            use_item_drugs(items, map->player);
        }
        *is_picked = false;
        map->inventory->items_slots_picked = -1;
    }
}
