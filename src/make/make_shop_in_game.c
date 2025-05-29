/*
** EPITECH PROJECT, 2024
** make_options
** File description:
** make_options
*/

#include "my.h"
#include "gui_struct.h"

static void make_item_shop(page_shop_item_t *item, game_t *game)
{
    make_img(item->item->background, game->window);
    make_img(item->item->icon, game->window);
    make_img(item->buy->img, game->window);
    make_img(item->sell->img, game->window);
    sfRenderWindow_drawText(game->window, item->name->txt, NULL);
    sfRenderWindow_drawText(game->window, item->nb_buy_txt->txt, NULL);
    sfRenderWindow_drawText(game->window, item->price_txt->txt, NULL);
}

static void make_list_menu(game_t *game, linked_list_t *lst, int offset)
{
    page_shop_item_t *item;
    int i = 0;

    while (lst && i < offset + 6) {
        item = ((page_shop_item_t *)(lst->data));
        if (i >= offset)
            make_item_shop(item, game);
        lst = lst->next;
        i++;
    }
}

static void default_page_shop(page_shop_t *options, game_t *game)
{
    make_img(options->background, game->window);
    sfRenderWindow_drawText(game->window, options->title->txt, NULL);
    sfRenderWindow_drawText(game->window, options->line->txt, NULL);
    sfRenderWindow_drawText(game->window, options->shop_state_txt->txt, NULL);
    sfRenderWindow_drawText(game->window, options->euro_dollar->txt, NULL);
    sfRenderWindow_drawText(game->window, options->recap->Class->txt, NULL);
    sfRenderWindow_drawText(game->window, options->recap->Title->txt, NULL);
    make_img(options->Valider->img, game->window);
    make_button(options->Melee, game);
    make_button(options->Ranged, game);
    make_button(options->Armor, game);
    make_button(options->Items, game);
    make_button(options->Cyberware, game);
}

void make_shop_in_game(ui_obj_t *obj, game_t *game)
{
    page_shop_t *options = (page_shop_t *)obj->ui_content;

    default_page_shop(options, game);
    if (options->state == MELEE_WEAPON_SHOP)
        make_list_menu(game, options->items_melee, options->offset);
    if (options->state == RANGED_WEAPON_SHOP)
        make_list_menu(game, options->items_ranged, options->offset);
    if (options->state == ARMOR_SHOP)
        make_list_menu(game, options->items_armor, options->offset);
    if (options->state == ITEMS_SHOP)
        make_list_menu(game, options->items_other, options->offset);
    if (options->state == CYBERWARE_SHOP)
        make_list_menu(game, options->items_cyberware, options->offset);
    make_img(options->inc_offset->img, game->window);
    make_img(options->dec_offset->img, game->window);
}
