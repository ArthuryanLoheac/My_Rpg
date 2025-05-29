/*
** EPITECH PROJECT, 2024
** import inventory items
** File description:
** import_inventory_items
*/

#include "my.h"


static void add_items_item_inv_weapon(char **src, main_slots_t **inv)
{
    char **args = my_str_to_word_array(src[1], ",", 0);

    if (args && my_pointlen(args) == 5) {
        inv[atoi(src[0])]->items->weapon->magazine.x = atoi(args[1]);
        inv[atoi(src[0])]->items->weapon->durability.x = atoi(args[2]);
        inv[atoi(src[0])]->items->weapon->bonus_tohit = atoi(args[3]);
        inv[atoi(src[0])]->items->weapon->bonus_damage = atoi(args[4]);
    }
}

static void add_items_item_inv_armor(char **src, main_slots_t **inv)
{
    char **args = my_str_to_word_array(src[1], ",", 0);

    if (args && my_pointlen(args) == 2)
        inv[atoi(src[0])]->items->armor->sp.x = atoi(args[1]);
}

static void add_items_item_inv_ammo(char **src, main_slots_t **inv)
{
    char **args = my_str_to_word_array(src[1], ",", 0);

    if (args && my_pointlen(args) == 2)
        inv[atoi(src[0])]->items->ammo->amount.x = atoi(args[1]);
}

static void add_items_item_inv_drugs(char **src, main_slots_t **inv)
{
    char **args = my_str_to_word_array(src[1], ",", 0);

    if (args && my_pointlen(args) == 2)
        inv[atoi(src[0])]->items->drug->uses.x = atoi(args[1]);
}

static void add_items_item_inv(char *src, main_slots_t **inv, game_t *game)
{
    char **args = my_str_to_word_array(src, " :", 0);

    if (args && my_pointlen(args) == 2 && (my_strcmp(args[1], "0") != 0 &&
        my_strcmp(args[1], "null") != 0)) {
        inv[atoi(args[0])]->items = init_item(atoi(args[1]), game->assets);
        sfSprite_setPosition(inv[atoi(args[0])]->items->icon->sprite,
            inv[atoi(args[0])]->position_icon);
        if (atoi(args[1]) >= 100 && atoi(args[1]) < 200)
            add_items_item_inv_armor(args, inv);
        if (atoi(args[1]) >= 200 && atoi(args[1]) < 300)
            add_items_item_inv_ammo(args, inv);
        if (atoi(args[1]) >= 300 && atoi(args[1]) < 400)
            add_items_item_inv_weapon(args, inv);
        if (atoi(args[1]) >= 400 && atoi(args[1]) < 500)
            add_items_item_inv_drugs(args, inv);
    }
    free_array(args);
}

void import_inventory_slots(game_t *game, main_slots_t **inv)
{
    char *data = import_from_save("Inventory", game->savefilepath);
    char **args = my_str_to_word_array(data, "\n\0", 0);

    for (int i = 0; args[i]; i++) {
        add_items_item_inv(args[i], inv, game);
    }
}
