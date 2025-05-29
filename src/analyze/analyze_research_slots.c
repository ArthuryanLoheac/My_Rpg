/*
** EPITECH PROJECT, 2024
** analyze_research_slot
** File description:
** analyze_research_slots
*/

#include "my.h"

static void switch_only_good_slots(map_t *map, int i, int k,
    bool *is_good_slots)
{
    main_slots_t **main_slots_v = map->inventory->inventory->main_slots;

    if (((main_slots_v[i]->slot_type == INVENTORY_SLOTS) ||
        (main_slots_v[i]->slot_type == CYBERWARE_SLOTS
        && main_slots_v[k]->items->type == CYBERWARE))) {
            check_void_slots(map, i, k, is_good_slots);
        return;
    }
    if ((main_slots_v[i]->slot_type == WEAPON_SLOTS && (main_slots_v[k]->
        items->type == AMMO || main_slots_v[k]->items->type == GEAR ||
        main_slots_v[k]->items->type == WEAPON))) {
            check_void_slots_wep(map, i, k, is_good_slots);
    }
    if ((main_slots_v[i]->slot_type == ARMOR_SLOTS && (main_slots_v[k]->
        items->type == GEAR || main_slots_v[k]->items->type == ARMOR))) {
            check_void_slots_armor(map, i, k, is_good_slots);
    }
}

static int check_out_inv(map_t *map, int k)
{
    sfFloatRect view_bg = sfSprite_getGlobalBounds
        (map->inventory->background->sprite);
    sfFloatRect view_item = sfSprite_getGlobalBounds
        (map->inventory->inventory->main_slots[k]->items->icon->sprite);
    item_t *item = NULL;

    if (sfFloatRect_intersects(&view_bg, &view_item, NULL) == sfFalse) {
        item = map->inventory->inventory->main_slots[k]->items;
        drop_item_with_item(&(map->entity_all), &map,
        sfSprite_getPosition(map->player->sprite->temp->sprite), item);
        map->inventory->inventory->main_slots[k]->items = NULL;
        return 1;
    }
    return 0;
}

void research_slots_inventory(map_t *map, game_t *game, int k)
{
    sfVector2f mouse_pos = get_mouse_pos(game->window);
    sfFloatRect rect_gb;
    bool is_good_slots = false;

    if (check_out_inv(map, k) == 1)
        return;
    for (int i = 0; i < 20; i++) {
        if (!map->inventory->inventory->main_slots[i])
            continue;
        rect_gb = sfSprite_getGlobalBounds(map->inventory->inventory->
            main_slots[i]->background->sprite);
        if (sfFloatRect_contains(&rect_gb, mouse_pos.x,
            mouse_pos.y) == sfTrue) {
            switch_only_good_slots(map, i, k, &is_good_slots);
        }
    }
    if (is_good_slots == false)
        sfSprite_setPosition(map->inventory->inventory->main_slots[k]->items->
            icon->sprite, map->inventory->inventory->main_slots[k]->
            position_icon);
}

static void get_str(int i, map_t *map)
{
    char str[256];
    int letter = 0;
    int j = 0;
    int space = 0;

    sprintf(str, "%s :\n\n%s",
        map->inventory->inventory->main_slots[i]->items->name,
        map->inventory->inventory->main_slots[i]->items->desc);
    while (str[j] != '\0') {
        if (letter >= 27)
            space = 1;
        if ((str[j] == ' ' && space == 1) || str[j] == '\n') {
            space = 0;
            str[j] = '\n';
            letter = 0;
        }
        letter++;
        j++;
    }
    sfText_setString(map->inventory->logo->txt->txt, str);
}

void research_items_selected(map_t *map, game_t *game, bool *is_picked)
{
    sfVector2f mouse_pos = get_mouse_pos(game->window);
    sfFloatRect rec_rect;

    for (int i = 0; i < 20; i++) {
        if (!(map->inventory->inventory->main_slots[i]) ||
            !(map->inventory->inventory->main_slots[i]->items))
            continue;
        rec_rect = sfSprite_getGlobalBounds(map->inventory->inventory->
                main_slots[i]->items->icon->sprite);
        if (sfFloatRect_contains(&rec_rect, mouse_pos.x, mouse_pos.y)
            == sfTrue) {
            sfSprite_setPosition(map->inventory->inventory->main_slots[i]->
            items->icon->sprite, mouse_pos);
            map->inventory->items_slots_picked = i;
            get_str(i, map);
            *is_picked = true;
            break;
        }
    }
}
