/*
** EPITECH PROJECT, 2024
** analyze_options
** File description:
** analyze_options
*/

#include "my.h"
#include "gui_struct.h"

static void update_state_button_valider(gui_obj_t *button,
    guis_t *gui, game_t *game, page_shop_t *options)
{
    sfSprite_setColor(button->img->sprite, sfWhite);
    if (button->state == RELEASED) {
        compute_transfer_every_item_buyed(options, game);
        gui->active = PAGE_FINAL;
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_inc_offset(gui_obj_t *button,
    page_shop_t *options)
{
    sfSprite_setColor(button->img->sprite, sfWhite);
    if (button->state == RELEASED) {
        options->offset += 1;
        compute_pos_x_offset(get_actual_list_shop(options), options->offset);
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_dec_offset(gui_obj_t *button,
    page_shop_t *options)
{
    sfSprite_setColor(button->img->sprite, sfWhite);
    if (button->state == RELEASED) {
        options->offset -= 1;
        compute_pos_x_offset(get_actual_list_shop(options), options->offset);
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_melee(button_t *button, page_shop_t *options)
{
    sfSprite_setColor(button->gui_obj->img->sprite, sfWhite);
    if (button->gui_obj->state == RELEASED) {
        options->state = MELEE_WEAPON_SHOP;
        options->offset = 0;
        compute_pos_x_offset(get_actual_list_shop(options), options->offset);
        button->gui_obj->state = NO_STATE;
        sfText_setString(options->shop_state_txt->txt, "Shop : Melee weapons");
    }
    compute_default_state_button(button);
}

static void update_state_button_ranged(button_t *button, page_shop_t *options)
{
    sfSprite_setColor(button->gui_obj->img->sprite, sfWhite);
    if (button->gui_obj->state == RELEASED) {
        options->state = RANGED_WEAPON_SHOP;
        options->offset = 0;
        compute_pos_x_offset(get_actual_list_shop(options), options->offset);
        button->gui_obj->state = NO_STATE;
        sfText_setString(options->shop_state_txt->txt,
            "Shop : Ranged weapons");
    }
    compute_default_state_button(button);
}

static void update_state_button_armor(button_t *button, page_shop_t *options)
{
    sfSprite_setColor(button->gui_obj->img->sprite, sfWhite);
    if (button->gui_obj->state == RELEASED) {
        options->state = ARMOR_SHOP;
        options->offset = 0;
        compute_pos_x_offset(get_actual_list_shop(options), options->offset);
        button->gui_obj->state = NO_STATE;
        sfText_setString(options->shop_state_txt->txt, "Shop : Armors");
    }
    compute_default_state_button(button);
}

static void update_state_button_items(button_t *button, page_shop_t *options)
{
    sfSprite_setColor(button->gui_obj->img->sprite, sfWhite);
    if (button->gui_obj->state == RELEASED) {
        options->state = ITEMS_SHOP;
        options->offset = 0;
        compute_pos_x_offset(get_actual_list_shop(options), options->offset);
        button->gui_obj->state = NO_STATE;
        sfText_setString(options->shop_state_txt->txt, "Shop : Items");
    }
    compute_default_state_button(button);
}

static void update_state_button_cyberware(button_t *button,
    page_shop_t *options)
{
    sfSprite_setColor(button->gui_obj->img->sprite, sfWhite);
    if (button->gui_obj->state == RELEASED) {
        options->state = CYBERWARE_SHOP;
        options->offset = 0;
        compute_pos_x_offset(get_actual_list_shop(options), options->offset);
        button->gui_obj->state = NO_STATE;
        sfText_setString(options->shop_state_txt->txt, "Shop : Cyberware");
    }
    compute_default_state_button(button);
}

static void check_compute_button(page_shop_t *options)
{
    if (options->state != MELEE_WEAPON_SHOP)
        update_state_button_melee(options->Melee, options);
    if (options->state != RANGED_WEAPON_SHOP)
        update_state_button_ranged(options->Ranged, options);
    if (options->state != ARMOR_SHOP)
        update_state_button_armor(options->Armor, options);
    if (options->state != ITEMS_SHOP)
        update_state_button_items(options->Items, options);
    if (options->state != CYBERWARE_SHOP)
        update_state_button_cyberware(options->Cyberware, options);
}

void compute_shop(ui_obj_t *obj, game_t *game)
{
    page_shop_t *options = (page_shop_t *)obj->ui_content;
    static bool i = false;

    update_state_button_valider(options->Valider, game->guis, game, options);
    compute_everyone_transparent(options);
    check_compute_button(options);
    compute_buy_sell(options, game);
    if (options->offset + 6 < my_list_size(get_actual_list_shop(options)))
        update_state_button_inc_offset(options->inc_offset, options);
    if (options->offset > 0)
        update_state_button_dec_offset(options->dec_offset, options);
    if (i == false) {
        compute_recap_shop(options->recap, game->player, game->player->stats);
        i = true;
    }
}
