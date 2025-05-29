/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

static void move_items_picked(map_t *map, game_t *game, int i)
{
    sfVector2f mouse_pos = get_mouse_pos(game->window);

    sfSprite_setPosition(map->inventory->inventory->main_slots[i]
        ->items->icon->sprite, mouse_pos);
}

static void replace_img(img_t **img, assets_t **assets, char *src)
{
    sfVector2f pos = {0, 0};

    pos = sfSprite_getPosition((*img)->sprite);
    destroy_image((*img));
    (*img) = init_image(get_asset(src,
        assets), pos, 1);
}

static void set_correct_slots_init_item(main_slots_t ***slots, int i,
    game_t *game)
{
    if ((*slots)[i]->items) {
        if ((i > -1 && i < 2) || (i > 3 && i < 6) || i == 9) {
            replace_img(&((*slots)[i]->background), game->assets,
                "Inventory_icon_cyberware_full");
        }
        if (i == 8) {
            replace_img(&((*slots)[i]->background), game->assets,
                "Inventory_icon_armor_full");
        }
        if (i == 12) {
            replace_img(&((*slots)[i]->background), game->assets,
                "Inventory_icon_weapon_full");
        }
    }
}

static void set_correct_slots_uninit_item(main_slots_t ***slots, int i,
    game_t *game)
{
    if (!((*slots)[i]->items)) {
        if ((i > -1 && i < 2) || (i > 3 && i < 6) || i == 9) {
            replace_img(&((*slots)[i]->background), game->assets,
                "Inventory_icon_cyberware_empty");
        }
        if (i == 8) {
            replace_img(&((*slots)[i]->background), game->assets,
                "Inventory_icon_armor_empty");
        }
        if (i == 12) {
            replace_img(&((*slots)[i]->background), game->assets,
                "Inventory_icon_weapon_empty");
        }
    }
}

static void set_correct_slots_bg(map_t *map, game_t *game)
{
    main_slots_t **slots = map->inventory->inventory->main_slots;

    for (int i = 0; i < 20; i++) {
        if (!slots[i])
            continue;
        set_correct_slots_init_item(&slots, i, game);
        set_correct_slots_uninit_item(&slots, i, game);
    }
}

static void set_correct_slots_class(enum class_e class, gui_inventory_t **inv)
{
    if (class == SOLO || class == MED) {
        if ((*inv)->inventory->main_slots[9])
            (*inv)->inventory->main_slots[9] = NULL;
        if ((*inv)->inventory->main_slots[18])
            (*inv)->inventory->main_slots[18] = NULL;
        if ((*inv)->inventory->main_slots[19])
            (*inv)->inventory->main_slots[19] = NULL;
    }
}

void compute_inventory(map_t *map, game_t *game)
{
    set_correct_slots_class(game->player->class, &(map->inventory));
    set_correct_slots_bg(map, game);
    if (map->inventory->items_slots_picked != -1)
        move_items_picked(map, game, map->inventory->items_slots_picked);
}
