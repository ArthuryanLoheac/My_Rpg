/*
** EPITECH PROJECT, 2024
** init inventory setslots
** File description:
** init_inventory_set_sots
*/

#include "my.h"


static sfVector2f set_image_slots_sec(main_slots_t *data,
    int i, sfVector2f pos, assets_t **assets)
{
    if ((i >= 2 && i < 4) || (i >= 6 && i < 8) || (i >= 10 && i < 14) ||
        (i >= 14 && i < 16) || i == 18 || i == 19 || i == 13 || i == 16
        || i == 17) {
        data->background = init_image(get_asset("Inventory_icon_normal",
            assets), pos, 1);
        data->slot_type = INVENTORY_SLOTS;
    }
    if (i == 12) {
        data->background = init_image(get_asset("Inventory_icon_weapon_empty",
            assets), pos, 1);
        data->slot_type = WEAPON_SLOTS;
    }
    return pos;
}

sfVector2f set_image_slots(main_slots_t *data, int i, sfVector2f pos,
    assets_t **assets)
{
    if (i < 2 || (i >= 4 && i < 6) || (i == 9)) {
        data->background = init_image(get_asset(
            "Inventory_icon_cyberware_empty", assets), pos, 1);
        data->slot_type = CYBERWARE_SLOTS;
    }
    if (i == 8) {
        data->background = init_image(get_asset("Inventory_icon_armor_empty",
            assets), pos, 1);
        data->slot_type = ARMOR_SLOTS;
    }
    pos = set_image_slots_sec(data, i, pos, assets);
    return pos;
}
