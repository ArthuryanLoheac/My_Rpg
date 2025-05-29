/*
** EPITECH PROJECT, 2024
** init_options
** File description:
** init_options
*/

#include "my.h"
#include "guis.h"
#include "gui_struct.h"

static void init_title(page_shop_t *page, assets_t **assets)
{
    page->title = init_label("CHOOSE YOUR STUFFS",
        (sfVector2f){680, 130}, 30, get_asset("Font_pixel", assets));
    sfText_setColor(page->title->txt, ORANGE);
    page->shop_state_txt = init_label("Shop : Melee weapons",
        (sfVector2f){600, 220}, 20, get_asset("Font_pixel", assets));
    page->line = init_label("---------------------"
    "--------------------",
        (sfVector2f){600, 265}, 15, get_asset("Font_pixel", assets));
    page->euro_dollar = init_label("2250 E$",
        (sfVector2f){1160, 220}, 20, get_asset("Font_pixel", assets));
    sfText_setColor(page->euro_dollar->txt, ORANGE);
}

button_t *init_one_button(assets_t **assets, char *txt, int i)
{
    sfVector2f size = {280, 80};
    sfVector2f pos = {100, 100 + (i * 100)};
    button_t *obj = init_button(pos, size, txt, assets);

    return obj;
}

static void init_buttons(page_shop_t *page, assets_t **assets)
{
    sfVector2f size = {280, 80};
    sfVector2f pos = {1060, 945};

    page->Valider = init_gui_obj(pos, size);
    page->Valider->img = init_image(
        get_asset("Boutton_Valider", assets), pos, 1);
    init_animated_img(page->Valider->img, size.y, size.x, pos);
    page->Melee = init_one_button(assets, "MELEE", 0);
    page->Ranged = init_one_button(assets, "RANGED", 1);
    page->Armor = init_one_button(assets, "ARMOR", 2);
    page->Items = init_one_button(assets, "OTHER", 3);
    page->Cyberware = init_one_button(assets, "CYBER", 4);
}

static void init_recap(page_shop_t *page, assets_t **assets)
{
    page->recap = malloc(sizeof(recap_t));
    page->recap->Title = init_label("Summary", (sfVector2f){1450, 150}, 25,
        get_asset("Font_pixel", assets));
    page->recap->Class = init_label("Class : No Class",
        (sfVector2f){1450, 220}, 15, get_asset("Font_pixel", assets));
}

static void init_cyberware(linked_list_t **ll, assets_t **assets)
{
    for (int i = 1; i <= 4; i++)
        my_insert_back_list(ll,
            init_item_shop(assets, 600 + i, i - 1));
    for (int i = 8; i <= 11; i++)
        my_insert_back_list(ll,
            init_item_shop(assets, 600 + i, (i - 4) - 1));
    my_insert_back_list(ll,
            init_item_shop(assets, 600 + 15, 11 - 1));
    for (int i = 17; i <= 19; i++)
        my_insert_back_list(ll,
            init_item_shop(assets, 600 + i, (i - 12) - 1));
}

static void init_items_next(page_shop_t *page, assets_t **assets,
    enum class_e class)
{
    page->items_other = NULL;
    for (int i = 1; i <= 5; i++)
        my_insert_back_list(&page->items_other,
            init_item_shop(assets, 200 + i, i - 1));
    if (class == MED) {
        for (int i = 1; i <= 2; i++)
            my_insert_back_list(&page->items_other,
                init_item_shop(assets, 400 + i, i - 1 + 5));
    }
    for (int i = 1; i <= 5; i++)
        my_insert_back_list(&page->items_other,
            init_item_shop(assets, 500 + i, i - 1 + 9));
    page->items_cyberware = NULL;
    init_cyberware(&page->items_cyberware, assets);
}

static void init_items(page_shop_t *page, assets_t **assets,
    enum class_e class)
{
    page->items_melee = NULL;
    for (int i = 10; i <= 13; i++)
        my_insert_back_list(&page->items_melee,
            init_item_shop(assets, 300 + i, i - 10));
    page->items_ranged = NULL;
    for (int i = 1; i <= 9; i++)
        my_insert_back_list(&page->items_ranged,
            init_item_shop(assets, 300 + i, i - 1));
    page->items_armor = NULL;
    for (int i = 1; i <= 7; i++)
        my_insert_back_list(&page->items_armor,
            init_item_shop(assets, 100 + i, i - 1));
    init_items_next(page, assets, class);
}

static void init_offset(page_shop_t *page, assets_t **assets)
{
    sfVector2f size = {56, 56};
    sfVector2f pos_plus = {960, 945};
    sfVector2f pos_moins = {860, 945};

    page->offset = 0;
    page->inc_offset = init_gui_obj(pos_plus, size);
    page->inc_offset->img = init_image(
        get_asset("Boutton_Plus", assets), pos_plus, 1);
    init_animated_img(page->inc_offset->img, size.y, size.x, pos_plus);
    page->dec_offset = init_gui_obj(pos_moins, size);
    page->dec_offset->img = init_image(
        get_asset("Boutton_Moins", assets), pos_moins, 1);
    init_animated_img(page->dec_offset->img, size.y, size.x, pos_moins);
}

page_shop_t *init_shop(assets_t **assets, enum class_e class)
{
    page_shop_t *page = malloc(sizeof(page_shop_t));

    init_items(page, assets, class);
    page->state = MELEE_WEAPON_SHOP;
    init_title(page, assets);
    init_buttons(page, assets);
    page->background = init_image(
        get_asset("Choose_BG", assets), vect0(), 1);
    init_offset(page, assets);
    init_recap(page, assets);
    page->nb_items = malloc(sizeof(nb_item_buyed_t));
    page->nb_items->armor = 0;
    page->nb_items->cyberware = 0;
    page->nb_items->other = 0;
    page->nb_items->weapon = 0;
    return page;
}
