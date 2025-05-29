/*
** EPITECH PROJECT, 2024
** compute_item
** File description:
** compute_item
*/
#include "my.h"
#include "gui_struct.h"

static void update_number_items(page_shop_item_t *item,
    nb_item_buyed_t *nb_item, int buy)
{
    if (item->item->type == WEAPON)
        nb_item->weapon += (buy * 2) - 1;
    if (item->item->type == CYBERWARE)
        nb_item->cyberware += (buy * 2) - 1;
    if (item->item->type == ARMOR)
        nb_item->armor += (buy * 2) - 1;
    if (item->item->type == AMMO || item->item->type == DRUGS ||
        item->item->type == GEAR)
        nb_item->other += (buy * 2) - 1;
}

static void update_nb_buy_txt(page_shop_item_t *item, bool buy,
    nb_item_buyed_t *nb_item)
{
    char str[100];
    sfVector2f pos = sfText_getPosition(item->nb_buy_txt->txt);

    sprintf(str, "%d", item->nb_buy);
    sfText_setString(item->nb_buy_txt->txt, str);
    if (item->nb_buy == 10) {
        pos.x = 1230;
        sfText_setPosition(item->nb_buy_txt->txt, pos);
    }
    if (item->nb_buy == 9) {
        pos.x = 1244;
        sfText_setPosition(item->nb_buy_txt->txt, pos);
    }
    update_number_items(item, nb_item, buy);
}

static void update_state_button_buy(gui_obj_t *button, page_shop_item_t *item,
    player_character_t *player, nb_item_buyed_t *nb_item)
{
    sfSprite_setColor(button->img->sprite, sfWhite);
    if (button->state == RELEASED) {
        item->nb_buy += 1;
        player->euro_dollars -= item->price;
        update_nb_buy_txt(item, 1, nb_item);
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_sell(gui_obj_t *button, page_shop_item_t *item,
    player_character_t *player, nb_item_buyed_t *nb_item)
{
    sfSprite_setColor(button->img->sprite, sfWhite);
    if (button->state == RELEASED) {
        item->nb_buy -= 1;
        player->euro_dollars += item->price;
        update_nb_buy_txt(item, 0, nb_item);
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static int min_zero(int x)
{
    if (x < 0)
        return 0;
    return x;
}

static int nbr_slot_cyber(enum class_e class)
{
    if (class == SOLO || class == MED)
        return 4;
    else
        return 5;
}

static void check_update_button_buy_types_second(page_shop_item_t *item,
    player_character_t *player, nb_item_buyed_t *nb_item,
    enum type_shop_e state)
{
    if (state == ARMOR_SHOP && item->price <= player->euro_dollars &&
        (nb_item->other + min_zero(nb_item->weapon - 1) + min_zero(nb_item->
        cyberware - nbr_slot_cyber(player->class)) + nb_item->armor +
        nbr_slot_armor(player->inventory->main_slots)) <= 13 -
        nbr_max_slot(player->class, player->inventory->main_slots))
        update_state_button_buy(item->buy, item, player, nb_item);
    if (state == ITEMS_SHOP && item->price <= player->euro_dollars &&
        (nb_item->other + min_zero(nb_item->weapon - 1) +
        min_zero(nb_item->cyberware - nbr_slot_cyber(player->class)) +
        min_zero(nb_item->armor - 1)) <= 12 - nbr_max_slot(player->class,
        player->inventory->main_slots))
        update_state_button_buy(item->buy, item, player, nb_item);
}

static void check_update_button_buy_types(page_shop_item_t *item,
    player_character_t *player, nb_item_buyed_t *nb_item,
    enum type_shop_e state)
{
    if ((state == MELEE_WEAPON_SHOP || state == RANGED_WEAPON_SHOP) &&
        item->price <= player->euro_dollars &&
        (nb_item->other + nb_item->weapon +
        nbr_slot_wep(player->inventory->main_slots) +
        min_zero(nb_item->cyberware - nbr_slot_cyber(player->class)) +
        min_zero(nb_item->armor - 1)) <= 13 - nbr_max_slot(player->class,
        player->inventory->main_slots))
        update_state_button_buy(item->buy, item, player, nb_item);
    if (state == CYBERWARE_SHOP && item->price <= player->euro_dollars &&
        (nb_item->other + min_zero(nb_item->weapon - 1) + nb_item->cyberware +
        nbr_slot_cyber_inv(player->inventory->main_slots) +
        min_zero(nb_item->armor - 1)) <= 17 -
        nbr_max_slot(player->class, player->inventory->main_slots))
        update_state_button_buy(item->buy, item, player, nb_item);
    check_update_button_buy_types_second(item, player, nb_item, state);
}

void compute_item(linked_list_t *lst, player_character_t *player,
    nb_item_buyed_t *nb_item, enum type_shop_e state)
{
    page_shop_item_t *item;

    while (lst) {
        item = ((page_shop_item_t *)(lst->data));
        check_update_button_buy_types(item, player, nb_item, state);
        if (item->nb_buy > 0)
            update_state_button_sell(item->sell, item, player, nb_item);
        lst = lst->next;
    }
}
