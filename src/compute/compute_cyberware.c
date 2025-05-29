/*
** EPITECH PROJECT, 2024
** compute_cyberware
** File description:
** compute_cyberware
*/

#include "my.h"

static void restore_default_player_stats(player_character_t **pc)
{
    if (!((*pc)->bonus_stats))
        return;
    else {
        ((*pc)->stats)->BODY -= ((*pc)->bonus_stats)->BODY;
        ((*pc)->stats)->DEX -= ((*pc)->bonus_stats)->DEX;
        ((*pc)->stats)->EMP -= ((*pc)->bonus_stats)->EMP;
        ((*pc)->stats)->HUM += ((*pc)->bonus_stats)->HUM;
        ((*pc)->stats)->LUCK -= ((*pc)->bonus_stats)->LUCK;
        ((*pc)->stats)->MOVE -= ((*pc)->bonus_stats)->MOVE;
        ((*pc)->stats)->REF -= ((*pc)->bonus_stats)->REF;
        ((*pc)->stats)->TECH -= ((*pc)->bonus_stats)->TECH;
        ((*pc)->stats)->WILL -= ((*pc)->bonus_stats)->WILL;
        free((*pc)->bonus_stats);
    }
}

static stats_t *init_bonus_stats(void)
{
    stats_t *data = malloc(sizeof(stats_t));

    data->BODY = 0;
    data->DEX = 0;
    data->EMP = 0;
    data->HUM = 0;
    data->LUCK = 0;
    data->MOVE = 0;
    data->REF = 0;
    data->TECH = 0;
    data->WILL = 0;
    return data;
}

static void set_stats_cyber_second(int n, item_t *item,
    player_character_t **pc)
{
    if (item->id % 100 == 3){
        (*pc)->bonus_stats->REF += 1;
        if ((*pc)->stats->HUM >= (unsigned int)(8 * n)) {
            (*pc)->bonus_stats->HUM += 8;
            n++;
        }
    }
    if (item->id % 100 == 4){
        (*pc)->bonus_stats->DEX += 1;
        if ((*pc)->stats->HUM >= (unsigned int)(8 * n)) {
            (*pc)->bonus_stats->HUM += 8;
            n++;
        }
    }
}

static void set_stats_cyber(item_t *item, player_character_t **pc)
{
    int n = 1;

    if (item->id % 100 == 1){
        (*pc)->bonus_stats->BODY += 1;
        if ((*pc)->stats->HUM >= (unsigned int)(8 * n)) {
            (*pc)->bonus_stats->HUM += 8;
            n++;
        }
    }
    if (item->id % 100 == 2){
        (*pc)->bonus_stats->MOVE += 1;
        if ((*pc)->stats->HUM >= (unsigned int)(8 * n)) {
            (*pc)->bonus_stats->HUM += 8;
            n++;
        }
    }
    set_stats_cyber_second(n, item, pc);
}

static void refresh_stats(player_character_t **pc)
{
    ((*pc)->stats)->BODY += ((*pc)->bonus_stats)->BODY;
    ((*pc)->stats)->DEX += ((*pc)->bonus_stats)->DEX;
    ((*pc)->stats)->EMP += ((*pc)->bonus_stats)->EMP;
    ((*pc)->stats)->HUM -= ((*pc)->bonus_stats)->HUM;
    ((*pc)->stats)->LUCK += ((*pc)->bonus_stats)->LUCK;
    ((*pc)->stats)->MOVE += ((*pc)->bonus_stats)->MOVE;
    ((*pc)->stats)->REF += ((*pc)->bonus_stats)->REF;
    ((*pc)->stats)->TECH += ((*pc)->bonus_stats)->TECH;
    ((*pc)->stats)->WILL += ((*pc)->bonus_stats)->WILL;
}

void compute_cyberware(map_t *map)
{
    main_slots_t **slots = map->inventory->inventory->main_slots;

    restore_default_player_stats(&(map->player));
    map->player->bonus_stats = init_bonus_stats();
    for (int i = 0; i < 20; i++) {
        if (((i > -1 && i < 2) || (i > 3 && i < 6) || i == 9) &&
            slots[i] && slots[i]->items)
            set_stats_cyber(slots[i]->items, &(map->player));
    }
    refresh_stats(&map->player);
    init_txt_stats(map->inventory->stats_area->text,
        map->player->stats, map->player->class);
}
