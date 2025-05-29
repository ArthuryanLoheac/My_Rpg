/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to create a button
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/lib.h"
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

static void set_item(item_t *item)
{
    set_weapon_stats(item, (int[]){99, 99999, 0, 0});
    set_armor_stats(item, 99);
    set_ammo_stats(item, 99);
    set_cyberware_stats(item, 4);
    set_gear_stats(item);
    set_drugs_stats(item, 99);
}

static int set_price_items(char **data_file)
{
    if (!data_file[2])
        return 0;
    else
        return atoi(data_file[2]);
}

static void add_name_desc_item_price(item_t **items, assets_t **assets)
{
    char **data_file = my_str_to_word_array(open_file(get_asset(my_strcat_data(
        int_to_str((*items)->id)), assets)), ";", 0);

    if (!data_file)
        return;
    if (!data_file[0])
        (*items)->name = NULL;
    else
        (*items)->name = my_strdup(data_file[0]);
    if (!data_file[1])
        (*items)->desc = NULL;
    else
        (*items)->desc = my_strdup(data_file[1]);
    (*items)->price_item = set_price_items(data_file);
}

static void init_basics(item_t *item, int id, assets_t **assets)
{
    item->id = id;
    add_name_desc_item_price(&item, assets);
    item->type = id / 100;
}

item_t *init_item(int id, assets_t **assets)
{
    item_t *item = malloc(sizeof(item_t));
    char *sprite_asset = get_asset(my_strcat_assets(int_to_str(id)),
        assets);
    sfFloatRect global_bounds;

    init_basics(item, id, assets);
    if (id / 100 == 3)
        item->icon = init_image(sprite_asset,
            vect0(), 0.81);
    else
        item->icon = init_image(sprite_asset,
            vect0(), 0.20);
    global_bounds = sfSprite_getLocalBounds(item->icon->sprite);
    sfSprite_setOrigin(item->icon->sprite, (sfVector2f){global_bounds.width
        / 2, global_bounds.height / 2});
    item->background = NULL;
    free(sprite_asset);
    set_item(item);
    return item;
}
