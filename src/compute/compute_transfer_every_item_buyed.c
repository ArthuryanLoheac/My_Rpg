/*
** EPITECH PROJECT, 2024
** buy_every_item
** File description:
** buy_every_item
*/
#include "my.h"
#include "gui_struct.h"

static void check_slot_melee(page_shop_item_t *item, main_slots_t **slots,
    type_slots_t PRIO, assets_t **assets)
{
    for (int i = 0; i < 20; i++) {
        if (slots[i] && slots[i]->items == NULL && item->nb_buy > 0 &&
            slots[i]->slot_type == PRIO) {
            slots[i]->items = init_item(item->item->id, assets);
            item->nb_buy--;
        }
    }
    for (int i = 0; i < 20; i++) {
        if (slots[i] && slots[i]->items == NULL && item->nb_buy > 0 &&
            slots[i]->slot_type == INVENTORY_SLOTS) {
            slots[i]->items = init_item(item->item->id, assets);
            item->nb_buy--;
        }
    }
}

static void transfer_melee(page_shop_t *options, main_slots_t **slots,
    assets_t **assets)
{
    linked_list_t *lst = options->items_melee;
    page_shop_item_t *item;

    while (lst) {
        item = ((page_shop_item_t *)(lst->data));
        check_slot_melee(item, slots, WEAPON_SLOTS, assets);
        lst = lst->next;
    }
}

static void transfer_armor(page_shop_t *options, main_slots_t **slots,
    assets_t **assets)
{
    linked_list_t *lst = options->items_armor;
    page_shop_item_t *item;

    while (lst) {
        item = ((page_shop_item_t *)(lst->data));
        check_slot_melee(item, slots, ARMOR_SLOTS, assets);
        lst = lst->next;
    }
}

static void transfer_ranged(page_shop_t *options, main_slots_t **slots,
    assets_t **assets)
{
    linked_list_t *lst = options->items_ranged;
    page_shop_item_t *item;

    while (lst) {
        item = ((page_shop_item_t *)(lst->data));
        check_slot_melee(item, slots, WEAPON_SLOTS, assets);
        lst = lst->next;
    }
}

static void transfer_cyberware(page_shop_t *options, main_slots_t **slots,
    assets_t **assets)
{
    linked_list_t *lst = options->items_cyberware;
    page_shop_item_t *item;

    while (lst) {
        item = ((page_shop_item_t *)(lst->data));
        check_slot_melee(item, slots, CYBERWARE_SLOTS, assets);
        lst = lst->next;
    }
}

static void transfer_items(page_shop_t *options, main_slots_t **slots,
    assets_t **assets)
{
    linked_list_t *lst = options->items_other;
    page_shop_item_t *item;

    while (lst) {
        item = ((page_shop_item_t *)(lst->data));
        check_slot_melee(item, slots, INVENTORY_SLOTS, assets);
        lst = lst->next;
    }
}

void compute_transfer_every_item_buyed(page_shop_t *options, game_t *game)
{
    main_slots_t **slots = ((map_t *)(game->guis->map->ui_content))
        ->inventory->inventory->main_slots;

    transfer_melee(options, slots, game->assets);
    transfer_ranged(options, slots, game->assets);
    transfer_armor(options, slots, game->assets);
    transfer_cyberware(options, slots, game->assets);
    transfer_items(options, slots, game->assets);
}
