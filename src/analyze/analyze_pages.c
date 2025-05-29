/*
** EPITECH PROJECT, 2024
** analyze_buttons_start_menu
** File description:
** analyze_buttons_start_menu
*/

#include "my.h"
void analyze_menu_main(ui_obj_t *obj, game_t *game)
{
    main_t *menu = (main_t *)obj->ui_content;

    analyze_gui_obj(game->window, game->events, menu->play);
    analyze_gui_obj(game->window, game->events, menu->settings);
    analyze_gui_obj(game->window, game->events, menu->quit);
}

static void analyze_keybinds(ui_obj_t *obj, game_t *game)
{
    page_options_t *options = (page_options_t *)obj->ui_content;

    analyze_gui_obj(game->window, game->events,
        options->keybinds_labels->up->change_bind);
    analyze_gui_obj(game->window, game->events,
        options->keybinds_labels->down->change_bind);
    analyze_gui_obj(game->window, game->events,
        options->keybinds_labels->left->change_bind);
    analyze_gui_obj(game->window, game->events,
        options->keybinds_labels->right->change_bind);
    analyze_gui_obj(game->window, game->events,
        options->keybinds_labels->attack->change_bind);
    analyze_gui_obj(game->window, game->events,
        options->keybinds_labels->interact->change_bind);
    analyze_gui_obj(game->window, game->events,
        options->keybinds_labels->inventory->change_bind);
    analyze_gui_obj(game->window, game->events,
        options->keybinds_labels->progression->change_bind);
    analyze_gui_obj(game->window, game->events,
        options->keybinds_labels->skip->change_bind);
}

void analyze_options(ui_obj_t *obj, game_t *game)
{
    page_options_t *options = (page_options_t *)obj->ui_content;

    analyze_gui_obj(game->window, game->events, options->retour);
    analyze_gui_obj(game->window, game->events, options->fullscreen->gui_obj);
    analyze_gui_obj(game->window, game->events, options->lower_volume);
    analyze_gui_obj(game->window, game->events, options->greater_volume);
    analyze_gui_obj(game->window, game->events, options->mute_volume->gui_obj);
    analyze_gui_obj(game->window, game->events,
        options->unmute_volume->gui_obj);
    analyze_gui_obj(game->window, game->events,
        options->min_resolution->gui_obj);
    analyze_gui_obj(game->window, game->events,
        options->mid_resolution->gui_obj);
    analyze_gui_obj(game->window, game->events,
        options->max_resolution->gui_obj);
    analyze_gui_obj(game->window, game->events, options->save->gui_obj);
    analyze_keybinds(obj, game);
    analyze_gui_obj(game->window, game->events, options->lower_volume_sound);
    analyze_gui_obj(game->window, game->events, options->greater_volume_sound);
}

void analyze_choose_class(ui_obj_t *obj, game_t *game)
{
    page_choose_class_t *options = (page_choose_class_t *)obj->ui_content;

    analyze_gui_obj(game->window, game->events, options->Class_one->Valider);
    analyze_gui_obj(game->window, game->events, options->Class_two->Valider);
    analyze_gui_obj(game->window, game->events, options->Class_three->Valider);
}

void analyze_choose_stats(ui_obj_t *obj, game_t *game)
{
    page_choose_stats_t *stats = (page_choose_stats_t *)obj->ui_content;

    analyze_gui_obj(game->window, game->events, stats->Valider);
    analyze_gui_obj(game->window, game->events, stats->DEX->Moins);
    analyze_gui_obj(game->window, game->events, stats->DEX->Plus);
    analyze_gui_obj(game->window, game->events, stats->MOVE->Moins);
    analyze_gui_obj(game->window, game->events, stats->MOVE->Plus);
    analyze_gui_obj(game->window, game->events, stats->TECH->Moins);
    analyze_gui_obj(game->window, game->events, stats->TECH->Plus);
    analyze_gui_obj(game->window, game->events, stats->BODY->Moins);
    analyze_gui_obj(game->window, game->events, stats->BODY->Plus);
    analyze_gui_obj(game->window, game->events, stats->WILL->Moins);
    analyze_gui_obj(game->window, game->events, stats->WILL->Plus);
    analyze_gui_obj(game->window, game->events, stats->REF->Moins);
    analyze_gui_obj(game->window, game->events, stats->REF->Plus);
    analyze_gui_obj(game->window, game->events, stats->LUCK->Moins);
    analyze_gui_obj(game->window, game->events, stats->LUCK->Plus);
    analyze_gui_obj(game->window, game->events, stats->EMP->Moins);
    analyze_gui_obj(game->window, game->events, stats->EMP->Plus);
}

static void analyze_item_shop(page_shop_item_t *item, game_t *game)
{
    analyze_gui_obj(game->window, game->events, item->buy);
    analyze_gui_obj(game->window, game->events, item->sell);
}

static void analyze_lst_shop(linked_list_t *lst, game_t *game, int offset)
{
    page_shop_item_t *item;
    int i = 0;

    while (lst && i < offset + 6) {
        item = ((page_shop_item_t *)(lst->data));
        if (i >= offset)
            analyze_item_shop(item, game);
        lst = lst->next;
        i++;
    }
}

void analyze_shop(ui_obj_t *obj, game_t *game)
{
    page_shop_t *options = (page_shop_t *)obj->ui_content;

    analyze_gui_obj(game->window, game->events, options->Valider);
    analyze_gui_obj(game->window, game->events, options->Melee->gui_obj);
    analyze_gui_obj(game->window, game->events, options->Ranged->gui_obj);
    analyze_gui_obj(game->window, game->events, options->Armor->gui_obj);
    analyze_gui_obj(game->window, game->events, options->Items->gui_obj);
    analyze_gui_obj(game->window, game->events, options->Cyberware->gui_obj);
    analyze_gui_obj(game->window, game->events, options->dec_offset);
    analyze_gui_obj(game->window, game->events, options->inc_offset);
    if (options->state == MELEE_WEAPON_SHOP)
        analyze_lst_shop(options->items_melee, game, options->offset);
    if (options->state == RANGED_WEAPON_SHOP)
        analyze_lst_shop(options->items_ranged, game, options->offset);
    if (options->state == ARMOR_SHOP)
        analyze_lst_shop(options->items_armor, game, options->offset);
    if (options->state == ITEMS_SHOP)
        analyze_lst_shop(options->items_other, game, options->offset);
    if (options->state == CYBERWARE_SHOP)
        analyze_lst_shop(options->items_cyberware, game, options->offset);
}
