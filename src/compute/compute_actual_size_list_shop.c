/*
** EPITECH PROJECT, 2024
** actual_size_list_shop
** File description:
** actual_size_list_shop
*/
#include "my.h"
#include "gui_struct.h"

linked_list_t *get_actual_list_shop(page_shop_t *options)
{
    if (options->state == MELEE_WEAPON_SHOP)
        return options->items_melee;
    if (options->state == RANGED_WEAPON_SHOP)
        return options->items_ranged;
    if (options->state == ARMOR_SHOP)
        return options->items_armor;
    if (options->state == ITEMS_SHOP)
        return options->items_other;
    if (options->state == CYBERWARE_SHOP)
        return options->items_cyberware;
    return NULL;
}
