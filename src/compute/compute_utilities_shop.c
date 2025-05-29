/*
** EPITECH PROJECT, 2024
** compute_utilities_shop
** File description:
** compute_utilities_shop
*/
#include "my.h"
#include "gui_struct.h"

static void make_lst_trans(linked_list_t *lst, int offset)
{
    sfColor trans = sfColor_fromRGBA(255, 255, 255, 128);
    page_shop_item_t *item;
    int i = 0;

    while (lst && i < offset + 6) {
        item = ((page_shop_item_t *)(lst->data));
        if (i >= offset) {
            sfSprite_setColor(item->buy->img->sprite, trans);
            sfSprite_setColor(item->sell->img->sprite, trans);
        }
        lst = lst->next;
        i++;
    }
}

static void compute_euro_dollar_txt(page_shop_t *options,
    player_character_t *player)
{
    char *str = malloc(sizeof(char) * 10);

    sprintf(str, "%d E$", player->euro_dollars);
    sfText_setString(options->euro_dollar->txt, str);
    free(str);
}

void compute_everyone_transparent(page_shop_t *options)
{
    sfColor trans = sfColor_fromRGBA(255, 255, 255, 128);
    sfColor orange_trans = sfColor_fromRGBA(ORANGE.r, ORANGE.g, ORANGE.b, 128);

    sfSprite_setColor(options->Melee->gui_obj->img->sprite, trans);
    sfText_setColor(options->Melee->text->txt, orange_trans);
    sfSprite_setColor(options->Ranged->gui_obj->img->sprite, trans);
    sfText_setColor(options->Ranged->text->txt, orange_trans);
    sfSprite_setColor(options->Armor->gui_obj->img->sprite, trans);
    sfText_setColor(options->Armor->text->txt, orange_trans);
    sfSprite_setColor(options->Items->gui_obj->img->sprite, trans);
    sfText_setColor(options->Items->text->txt, orange_trans);
    sfSprite_setColor(options->Cyberware->gui_obj->img->sprite, trans);
    sfText_setColor(options->Cyberware->text->txt, orange_trans);
    sfSprite_setColor(options->dec_offset->img->sprite, trans);
    sfSprite_setColor(options->inc_offset->img->sprite, trans);
    make_lst_trans(options->items_melee, options->offset);
    make_lst_trans(options->items_ranged, options->offset);
    make_lst_trans(options->items_armor, options->offset);
    make_lst_trans(options->items_other, options->offset);
    make_lst_trans(options->items_cyberware, options->offset);
}

void compute_buy_sell(page_shop_t *options, game_t *game)
{
    compute_euro_dollar_txt(options, game->player);
    if (options->state == MELEE_WEAPON_SHOP)
        compute_item(options->items_melee, game->player, options->nb_items,
            MELEE_WEAPON_SHOP);
    if (options->state == RANGED_WEAPON_SHOP)
        compute_item(options->items_ranged, game->player, options->nb_items,
            RANGED_WEAPON_SHOP);
    if (options->state == ARMOR_SHOP)
        compute_item(options->items_armor, game->player, options->nb_items,
            ARMOR_SHOP);
    if (options->state == ITEMS_SHOP)
        compute_item(options->items_other, game->player, options->nb_items,
            ITEMS_SHOP);
    if (options->state == CYBERWARE_SHOP)
        compute_item(options->items_cyberware, game->player, options->nb_items,
            CYBERWARE_SHOP);
}
