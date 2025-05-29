/*
** EPITECH PROJECT, 2024
** init_knife
** File description:
** init_knife
*/
#include "my.h"
#include "guis.h"
#include "gui_struct.h"

static void init_buy_parts(page_shop_item_t *item,
    assets_t **assets, int offset)
{
    sfVector2f size = {56, 56};
    sfVector2f pos_buy = {1290, 320 + offset};
    sfVector2f pos_sell = {1160, 320 + offset};

    item->nb_buy = 0;
    item->nb_buy_txt = init_label("0",
        (sfVector2f){1244, 340 + offset}, 20, get_asset("Font_pixel", assets));
    item->buy = init_gui_obj(pos_buy, size);
    item->buy->img = init_image(
        get_asset("Boutton_Plus", assets), pos_buy, 1);
    init_animated_img(item->buy->img, size.y, size.x, pos_buy);
    item->sell = init_gui_obj(pos_sell, size);
    item->sell->img = init_image(
        get_asset("Boutton_Moins", assets), pos_sell, 1);
    init_animated_img(item->sell->img, size.y, size.x, pos_sell);
}

static void init_price_txt(page_shop_item_t *item,
    int offset, assets_t **assets)
{
    char str[11];

    sprintf(str, "%dE$", item->price);
    item->price_txt = init_label(str,
        (sfVector2f){730, 360 + offset}, 15, get_asset("Font_pixel", assets));
    sfText_setColor(item->price_txt->txt, ORANGE);
}

page_shop_item_t *init_item_shop(assets_t **assets, int id, int pos)
{
    page_shop_item_t *item = NULL;
    int offset = pos * 100;

    item = malloc(sizeof(page_shop_item_t));
    init_buy_parts(item, assets, offset);
    item->item = init_item(id, assets);
    item->price = item->item->price_item;
    sfSprite_setPosition(item->item->icon->sprite,
        (sfVector2f){660, 345 + offset});
    if (id / 100 == 3)
        sfSprite_setScale(item->item->icon->sprite, (sfVector2f){0.60, 0.60});
    else
        sfSprite_setScale(item->item->icon->sprite, (sfVector2f){0.15, 0.15});
    item->item->background = init_image(get_asset("Inventory_icon_normal",
        assets), (sfVector2f){613, 300 + offset}, 0.75);
    item->name = init_label(item->item->name,
        (sfVector2f){730, 320 + offset}, 20, get_asset("Font_pixel", assets));
    init_price_txt(item, offset, assets);
    return item;
}
