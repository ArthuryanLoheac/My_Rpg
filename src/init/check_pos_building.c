/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** check_pos_building
*/
#include "my.h"

static void check_pos_red_house_little(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_RED_VERY_LITTLE)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_red_little"));
    for (int i = 10; i < 111 * SCALE_HOUSE; i++) {
        for (int j = 75 * SCALE_HOUSE; j < 150 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
}

static void check_pos_building_blue_three(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_BLUE_THREE)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_blue_3"));
    for (int i = 10; i < 167 * SCALE_HOUSE; i++) {
        for (int j = 197 * SCALE_HOUSE; j < 272 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
}

static void check_pos_building_blue_little(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_BLUE_LITTLE)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_blue_little"));
    for (int i = 10; i < 101 * SCALE_HOUSE; i++) {
        for (int j = 80 * SCALE_HOUSE; j < 155 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
}

static void check_pos_building_blue_long(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_BLUE_LONG)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_blue_long_2"));
    for (int i = 10; i < 206 * SCALE_HOUSE; i++) {
        for (int j = 107 * SCALE_HOUSE; j < 157 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
}

static void check_pos_building_red_three(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_RED_THREE)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_red_3"));
    for (int i = 10; i < 167.5 * SCALE_HOUSE; i++) {
        for (int j = 200 * SCALE_HOUSE; j < 275 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
}

static void check_pos_building_red_long(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_RED_LONG)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_red_long"));
    for (int i = 10; i < 245 * SCALE_HOUSE; i++) {
        for (int j = 79 * SCALE_HOUSE; j < 154 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
}

static void check_pos_building_red_long_two(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_RED_LONG_TWO)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_red_long_2"));
    for (int i = 10; i < 200 * SCALE_HOUSE; i++) {
        for (int j = 75 * SCALE_HOUSE; j < 150 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
}

static void check_pos_building_red_verylittle(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, HOUSE_RED_VERY_LITTLE)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_building_name(
        pos, assets, "Building_red_verylittle"));
    for (int i = 10; i < 72.5 * SCALE_HOUSE; i++) {
        for (int j = 77 * SCALE_HOUSE; j < 152 * SCALE_HOUSE; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
}

void check_pos_building(params_t params, game_t *game,
    linked_list_t **ll, map_t *map)
{
    check_pos_red_house_little(params, game->assets, ll, map);
    check_pos_building_blue_three(params, game->assets, ll, map);
    check_pos_building_blue_little(params, game->assets, ll, map);
    check_pos_building_blue_long(params, game->assets, ll, map);
    check_pos_building_red_three(params, game->assets, ll, map);
    check_pos_building_red_verylittle(params, game->assets, ll, map);
    check_pos_building_red_long_two(params, game->assets, ll, map);
    check_pos_building_red_long(params, game->assets, ll, map);
}
