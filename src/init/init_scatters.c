/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** init_scatters
*/
#include "my.h"

static void check_pos_trash(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, TRASH)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_trash(pos, assets));
    for (int i = - 48; i < 48; i++) {
        for (int j = - 24; j < 24; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
}

static void check_pos_lamp_l(params_t params,
    assets_t **assets, linked_list_t **ll)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, STREET_LAMP_R)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_street_lamp(pos, assets, 1));
}

static void check_pos_lamp_r(params_t params,
    assets_t **assets, linked_list_t **ll)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, STREET_LAMP_L)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_street_lamp(pos, assets, 0));
}

static void check_pos_lamp_n(params_t params,
    assets_t **assets, linked_list_t **ll)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, STREET_LAMP_N)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    my_insert_front_list(ll, init_street_lamp(pos, assets, 2));
}

static void check_pos_props(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, sfWhite) || is_same_color(color, sfGreen)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    if (pos.y >= 7 * 1080 && pos.x >= 7 * 1920)
        return;
    if (pos.y >= 7 * 1080 && pos.x <= 5 * 1920 && rand() % 7000 == 42)
        my_insert_front_list(ll, init_props(pos, assets, true));
    else if (rand() % 20000 == 42)
        my_insert_front_list(ll, init_props(pos, assets, false));
    if (rand() % 20000 != 42)
        return;
    my_insert_front_list(ll, init_bins(pos, assets));
    draw_rectangle(map, pos, (sfVector2f){-16, 16}, (sfVector2f){-16, 16});
}

static void check_pos_toxic_props(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, sfGreen)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    if (rand() % 10000 == 42)
        my_insert_front_list(ll, init_toxic_props(pos, assets, map));
    if (rand() % 20000 == 42)
        my_insert_front_list(ll, init_props_str(
            (sfVector2f){pos.x - 24, pos.y},
            assets, "Barrel_No_Collision_%d", 12));
}

static void check_pos_big_toxic_props(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    sfColor color = params.color;
    sfVector2f pos = params.pos;

    if (!(is_same_color(color, sfGreen)))
        return;
    pos = (sfVector2f){pos.x * 4, pos.y * 4};
    if (rand() % 20000 == 42) {
        my_insert_front_list(ll, init_props_str(
            (sfVector2f){pos.x - 96, pos.y - 80},
            assets, "Big_Toxic_Props_%d", 3));
        draw_rectangle(map, pos, (sfVector2f){-80, 80}, (sfVector2f){-32, 16});
    }
}

void check_pos_scatters(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map)
{
    check_pos_trash(params, assets, ll, map);
    check_pos_lamp_r(params, assets, ll);
    check_pos_lamp_l(params, assets, ll);
    check_pos_lamp_n(params, assets, ll);
    check_pos_props(params, assets, ll, map);
    check_pos_toxic_props(params, assets, ll, map);
    check_pos_big_toxic_props(params, assets, ll, map);
}
