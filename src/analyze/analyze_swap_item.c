/*
** EPITECH PROJECT, 2024
** analyse_drap_drop
** File description:
** analyze_drag_drop
*/

#include "my.h"

void swap_items(item_t **items1, item_t **items2)
{
    item_t *temp = *items1;

    *items1 = *items2;
    *items2 = temp;
}

void do_swap_item(map_t *map, int k, int i)
{
    sfSprite_setPosition(map->inventory->inventory->main_slots[k]->
        items->icon->sprite,
        map->inventory->inventory->main_slots[i]->position_icon);
    swap_items(&map->inventory->inventory->main_slots[k]->items, &map->
        inventory->inventory->main_slots[i]->items);
    if (map->inventory->inventory->main_slots[k]->items) {
        sfSprite_setPosition(map->inventory->inventory->main_slots[k]->
            items->icon->sprite, map->inventory->inventory->
            main_slots[k]->position_icon);
    }
    if ((i == 8 || k == 8) && map->fight->is_fight == true)
        map->fight->action_taken = true;
}
