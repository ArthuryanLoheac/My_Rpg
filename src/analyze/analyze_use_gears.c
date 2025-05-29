/*
** EPITECH PROJECT, 2024
** reload weapon
** File description:
** analyse_reaload_weapon
*/

#include "my.h"

static void reset_postion_gear_and_armor(main_slots_t *k, main_slots_t *i,
    bool is_weapon_dep)
{
    sfSprite_setPosition(k->items->icon->sprite, k->position_icon);
    if (k->items->gear->effect == USED) {
        destroy_image(k->items->icon);
        free(k->items->gear);
        free(k->items);
        k->items = NULL;
        if (is_weapon_dep) {
            sfSprite_setPosition(i->items->icon->sprite, k->position_icon);
            swap_items(&k->items, &i->items);
        }
    } else {
        sfSprite_setPosition(i->items->icon->sprite, i->position_icon);
    }
}

static void check_armor_patch(main_slots_t *k, main_slots_t *i,
    bool *is_reload, bool is_weapon_dep)
{
    int sp_max = 0;

    if (k->items && k->items->type == GEAR && i->items &&
        i->items->type == ARMOR && k->items->id % 100 == 1 &&
        i->items->armor->sp.x < i->items->armor->sp.y) {
        sp_max = i->items->armor->sp.y;
        i->items->armor->sp.x = sp_max;
        k->items->gear->effect = USED;
        *is_reload = true;
        reset_postion_gear_and_armor(k, i, is_weapon_dep);
    }
}

static void set_start_gears(main_slots_t **k, main_slots_t **i)
{
    item_t *items = (*k)->items;
    item_t *items_2 = (*i)->items;

    if (items->id % 100 == 2) {
        items_2->weapon->durability.x +=
            items_2->weapon->durability.y * 0.6;
        if (items_2->weapon->durability.x > items_2->weapon->durability.y)
            items_2->weapon->durability.x = items_2->weapon->durability.y;
    }
    if (items->id % 100 == 3)
        items_2->weapon->bonus_damage++;
    if (items->id % 100 == 4)
        items_2->weapon->bonus_tohit++;
    if (items->id % 100 == 5) {
        items_2->weapon->rof *= 2;
        items_2->weapon->bonus_tohit -= 5;
    }
}

static void check_upgrade_weapon(main_slots_t *k, main_slots_t *i,
    bool *is_reload, bool is_weapon_dep)
{
    if (k->items && i->items && k->items->type == GEAR &&
        i->items->type == WEAPON && k->items->id % 100 > 1 &&
        k->items->id % 100 <= 5) {
        set_start_gears(&k, &i);
        k->items->gear->effect = USED;
        *is_reload = true;
        reset_postion_gear_and_armor(k, i, is_weapon_dep);
    }
}

void analyze_use_gears(main_slots_t *k, main_slots_t *i,
    bool *is_reload, bool is_weapon_dep)
{
    check_armor_patch(k, i, is_reload, is_weapon_dep);
    check_upgrade_weapon(k, i, is_reload, is_weapon_dep);
}
