/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** check_all_houses
*/
#include "my.h"

static bool init_good_building(sfVector2f pos,
    assets_t **assets, linked_list_t **ll)
{
    if (rand() % 15 == 1) {
        my_insert_front_list(ll, init_building_shop(
            pos, assets, "House_Shop"));
        return 1;
    } else
        my_insert_front_list(ll, init_building_name(
            pos, assets, "Building_red_little"));
    return 0;
}

static int check_pos_red_house_little(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;
    bool shop = 0;

    if (!(is_same_color(color, HOUSE_RED_LITTLE)))
        return 0;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    shop = init_good_building(pos, assets, ll);
    draw_rectangle(map, pos, (sfVector2f){10,
        111 * SCALE_HOUSE - (shop * 40)},
        (sfVector2f){75 * SCALE_HOUSE, 150 * SCALE_HOUSE});
    if (shop)
        my_insert_front_list(ll, init_shop_scatter((sfVector2f)
        {pos.x + 120, pos.y + 260}, assets, map));
    return 1;
}

static int check_pos_building_blue_three(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_BLUE_THREE)))
        return 0;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_blue_3"));
    for (int i = 10; i < 167 * SCALE_HOUSE; i++) {
        for (int j = 197 * SCALE_HOUSE; j < 272 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
    return 1;
}

static int check_pos_building_blue_little(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_BLUE_LITTLE)))
        return 0;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_blue_little"));
    for (int i = 10; i < 101 * SCALE_HOUSE; i++) {
        for (int j = 80 * SCALE_HOUSE; j < 155 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
    return 1;
}

static int check_pos_building_blue_long(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_BLUE_LONG)))
        return 0;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_blue_long_2"));
    for (int i = 10; i < 206 * SCALE_HOUSE; i++) {
        for (int j = 107 * SCALE_HOUSE; j < 157 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
    return 1;
}

static int check_pos_building_red_three(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_RED_THREE)))
        return 0;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_red_3"));
    for (int i = 10; i < 167.5 * SCALE_HOUSE; i++) {
        for (int j = 200 * SCALE_HOUSE; j < 275 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
    return 1;
}

static int check_pos_building_red_long(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_RED_LONG)))
        return 0;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_red_long"));
    for (int i = 10; i < 245 * SCALE_HOUSE; i++) {
        for (int j = 79 * SCALE_HOUSE; j < 154 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
    return 1;
}

static int check_pos_building_red_long_two(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_RED_LONG_TWO)))
        return 0;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_red_long_2"));
    for (int i = 10; i < 200 * SCALE_HOUSE; i++) {
        for (int j = 75 * SCALE_HOUSE; j < 150 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
    return 1;
}

static int check_pos_building_red_verylittle(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_RED_VERY_LITTLE)))
        return 0;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_red_verylittle"));
    for (int i = 10; i < 72.5 * SCALE_HOUSE; i++) {
        for (int j = 77 * SCALE_HOUSE; j < 152 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
    return 1;
}

int check_all_houses(params_t params, game_t *game,
    linked_list_t **ll, map_t *map)
{
    int i = 0;

    i += check_pos_red_house_little(params, game->assets, ll, map);
    i += check_pos_building_blue_three(params, game->assets, ll, map);
    i += check_pos_building_blue_little(params, game->assets, ll, map);
    i += check_pos_building_blue_long(params, game->assets, ll, map);
    i += check_pos_building_red_three(params, game->assets, ll, map);
    i += check_pos_building_red_verylittle(params, game->assets, ll, map);
    i += check_pos_building_red_long_two(params, game->assets, ll, map);
    i += check_pos_building_red_long(params, game->assets, ll, map);
    return i;
}
