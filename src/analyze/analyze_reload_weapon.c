/*
** EPITECH PROJECT, 2024
** reload weapon
** File description:
** analyse_reaload_weapon
*/

#include "my.h"

static void reset_postion_ammo_and_weapon(main_slots_t *k, main_slots_t *i,
    bool is_weapon_dep)
{
    sfSprite_setPosition(k->items->icon->sprite, k->position_icon);
    if (k->items->ammo->amount.x == 0) {
        destroy_image(k->items->icon);
        free(k->items->ammo);
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

void analyze_reload_weapon(main_slots_t *k, main_slots_t *i,
    bool *is_reload, bool is_weapon_dep)
{
    int mag = 0;
    int max_bullets = 0;
    int bullets = 0;

    if (k->items->type == AMMO && i->items->type == WEAPON && i->items->weapon
        ->ammo_type_e == k->items->ammo->type && i->items->weapon->magazine.x
        != i->items->weapon->magazine.y) {
        mag = i->items->weapon->magazine.x;
        max_bullets = i->items->weapon->magazine.y;
        bullets = k->items->ammo->amount.x;
        mag = bullets + mag;
        if (max_bullets < mag) {
            k->items->ammo->amount.x = mag - max_bullets;
            mag = max_bullets;
        } else
            k->items->ammo->amount.x = 0;
        i->items->weapon->magazine.x = mag;
        *is_reload = true;
        reset_postion_ammo_and_weapon(k, i, is_weapon_dep);
    }
}
