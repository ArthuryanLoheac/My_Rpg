/*
** EPITECH PROJECT, 2024
** analyse_drap_drop
** File description:
** analyze_drag_drop
*/

#include "my.h"

static void check_slots_cyberware(main_slots_t *k, main_slots_t *i, map_t *map,
    bool *is_reload)
{
    if (k->items && k->slot_type != CYBERWARE_SLOTS &&
        k->items->type == CYBERWARE && i->slot_type ==
        CYBERWARE_SLOTS)
        if (map->player->stats->HUM < 8)
            (*is_reload) = true;
    if (i->items && i->slot_type != CYBERWARE_SLOTS &&
        i->items->type == CYBERWARE && k->slot_type ==
        CYBERWARE_SLOTS)
        if (map->player->stats->HUM < 8)
            (*is_reload) = true;
}

static void change_place_items(map_t *map, int k, int i, bool *is_good_slots)
{
    bool is_reload = false;
    main_slots_t **main_slots = map->inventory->inventory->main_slots;

    if ((i == 8 || k == 8) && map->fight->action_taken == true) {
        *is_good_slots = false;
        return;
    }
    if ((map->fight->is_fight == false || map->fight->action_taken == false) &&
        main_slots[i]->items && main_slots[k]->items) {
        analyze_reload_weapon(main_slots[k], main_slots[i], &is_reload, false);
        analyze_reload_weapon(main_slots[i], main_slots[k], &is_reload, true);
        analyze_use_gears(main_slots[k], main_slots[i], &is_reload, false);
        analyze_use_gears(main_slots[i], main_slots[k], &is_reload, true);
    }
    check_slots_cyberware(main_slots[k], main_slots[i], map, &is_reload);
    if (!is_reload && (main_slots[i]->slot_type != WEAPON_SLOTS ||
        main_slots[k]->items->type != AMMO)) {
        do_swap_item(map, k, i);
    } else if (map->fight->is_fight == true)
        map->fight->action_taken = true;
}

static bool is_valid_slot_combination(main_slots_t **slot, int i, int k)
{
    if ((slot[k]->slot_type == INVENTORY_SLOTS) ||
        (slot[k]->slot_type == CYBERWARE_SLOTS && slot[i]->items
        ->type == CYBERWARE))
        return true;
    return false;
}

void check_void_slots(map_t *map, int i, int k,
    bool *is_good_slots)
{
    main_slots_t **main_slots_v = map->inventory->inventory->main_slots;

    if (main_slots_v[i]->items) {
        if (is_valid_slot_combination(main_slots_v, i, k) == true) {
            *is_good_slots = true;
            change_place_items(map, k, i, is_good_slots);
            return;
        }
    } else {
        *is_good_slots = true;
        change_place_items(map, k, i, is_good_slots);
    }
}

void check_void_slots_wep(map_t *map, int i, int k,
    bool *is_good_slots)
{
    main_slots_t **main_slots_v = map->inventory->inventory->main_slots;

    if (main_slots_v[i]->items) {
        if (((main_slots_v[k]->slot_type == INVENTORY_SLOTS) ||
            (main_slots_v[k]->slot_type == WEAPON_SLOTS &&
            main_slots_v[i]->items->type == WEAPON))) {
            *is_good_slots = true;
            change_place_items(map, k, i, is_good_slots);
            return;
        }
        *is_good_slots = false;
    } else {
        if (main_slots_v[k]->items->type == WEAPON) {
            *is_good_slots = true;
            change_place_items(map, k, i, is_good_slots);
        }
    }
}

void check_void_slots_armor(map_t *map, int i, int k,
    bool *is_good_slots)
{
    main_slots_t **main_slots_v = map->inventory->inventory->main_slots;

    if (main_slots_v[i]->items) {
        if (((main_slots_v[k]->slot_type == INVENTORY_SLOTS) ||
            (main_slots_v[k]->slot_type == ARMOR_SLOTS &&
            main_slots_v[i]->items->type == ARMOR))) {
            *is_good_slots = true;
            change_place_items(map, k, i, is_good_slots);
            return;
        }
        *is_good_slots = false;
    } else {
        if (main_slots_v[k]->items->type == ARMOR) {
            *is_good_slots = true;
            change_place_items(map, k, i, is_good_slots);
        }
    }
}

static void check_drag_drop(map_t *map, game_t *game, bool *is_picked)
{
    if ((game->events->type == sfEvtMouseButtonPressed && game->events->
        mouseButton.button == sfMouseLeft) || *is_picked) {
        if (map->inventory->items_slots_picked == -1)
            research_items_selected(map, game, is_picked);
    }
    if ((game->events->type == sfEvtMouseButtonReleased && game->events->
        mouseButton.button == sfMouseLeft)) {
        if (*is_picked == true && map->inventory->items_slots_picked != -1)
            research_slots_inventory(map, game,
                map->inventory->items_slots_picked);
        *is_picked = false;
        map->inventory->items_slots_picked = -1;
    }
    check_use_items(map, game, is_picked);
}

void reset_postion_items(map_t *map)
{
    (void) map;
    for (int i = 0; i < 20; i++) {
        if (map->inventory->inventory->main_slots[i] &&
            map->inventory->inventory->main_slots[i]->items)
            sfSprite_setPosition(map->inventory->inventory->main_slots[i]->
                items->icon->sprite, map->inventory->inventory->
                main_slots[i]->position_icon);
    }
}

void analyze_inventory(ui_obj_t *obj, game_t *game)
{
    map_t *map = (map_t *)obj->ui_content;

    if (game->events->type == sfEvtKeyReleased && game->events->key.code ==
        game->keybinds->inventory && map->inventory->is_display == false) {
        map->inventory->is_display = true;
        compute_health_bar(map->inventory, map->view);
        init_txt_stats(map->inventory->stats_area->text,
            map->player->stats, map->player->class);
    } else if (game->events->type == sfEvtKeyReleased && game->events->key.code
        == game->keybinds->inventory && map->inventory->is_display == true) {
        map->inventory->is_display = false;
        reset_postion_items(map);
        map->inventory->is_picked = false;
        map->inventory->items_slots_picked = -1;
    }
    if (map && map->inventory->is_display == true)
        check_drag_drop(map, game, &map->inventory->is_picked);
}
