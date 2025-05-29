/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

void compute_shoot_line_pos(fight_gui_t *gui, sfVector2f pos1,
    sfVector2f pos2)
{
    sfVector2f dir = normalize(sub2(pos2, pos1));
    float angle_rad = get_angle(pos1, pos2);
    sfVector2f perp = {sin(angle_rad), -cos(angle_rad)};
    float width = 10.0f;
    int *dist = (int[]){1, 100, 300, 550, 900, 1350, 1900, 2550, 3300};
    sfVertex *vert = gui->points;

    perp = div3(mult3(perp, width), 2);
    for (int i = 0; i < 32; i++) {
        if (i % 4 == 0)
            vert[i].position = add2(add2(pos1, mult3(dir, dist[i / 4])), perp);
        if (i % 4 == 1)
            vert[i].position = add2(add2(pos1, mult3(dir, dist[i / 4 + 1])),
                perp);
        if (i % 4 == 2)
            vert[i].position = sub2(add2(pos1, mult3(dir, dist[i / 4 + 1])),
                perp);
        if (i % 4 == 3)
            vert[i].position = sub2(add2(pos1, mult3(dir, dist[i / 4])), perp);
    }
}

static sfColor get_color(weapon_t *weapon, unsigned int distance, unsigned int
    ATK, npc_t *target)
{
    int bonus;

    if (weapon == NULL)
        return (sfColor){255 - fmax(fmin((float)target->stats->DEX - ATK + 5.5,
            10), 0) * 25.5, 0, fmax(fmin((float)target->stats->DEX - ATK + 5.5,
            10), 0) * 25.5, 255};
    if (weapon->type >= 10 && weapon->type <= 13)
        return (sfColor){255 - fmax(fmin((float)target->stats->DEX - ATK + 5.5
            - weapon->bonus_tohit, 1), 0) * 255.0, 0, fmax(fmin((float)target
            ->stats->DEX - ATK + 5.5 - weapon->bonus_tohit, 1), 0) * 255.0,
            255};
    bonus = MAX((int)simulate_dv(weapon, distance / 50) - weapon->bonus_tohit -
        (int)ATK, 0);
    return (sfColor){255 - fmin((float)bonus / 10.0, 1) * 255.0, 0,
        fmin((float)bonus / 10.0, 1) * 255.0, 255};
}

static void default_line_color(map_t *map, weapon_t *weapon, npc_t *target)
{
    unsigned int ATK = map->player->stats->REF;
    int *dist = (int[]){1, 100, 300, 550, 900, 1350, 1900, 2550, 3300};

    if (weapon == NULL || (weapon->type >= 10 && weapon->type <= 13))
        ATK = map->player->stats->DEX;
    for (int i = 0; i < 32; i++) {
        if (i % 4 == 0)
            map->fight->gui->points[i].color = get_color(weapon, dist[i / 4],
                ATK, target);
        if (i % 4 == 1)
            map->fight->gui->points[i].color = get_color(weapon, dist[i / 4 +
                1], ATK, target);
        if (i % 4 == 2)
            map->fight->gui->points[i].color = get_color(weapon, dist[i / 4 +
                1], ATK, target);
        if (i % 4 == 3)
            map->fight->gui->points[i].color = get_color(weapon, dist[i / 4],
                ATK, target);
    }
}

void compute_shoot_line_color(map_t *map, sfVector2f pos1,
    sfVector2f pos2, weapon_t *weapon)
{
    if (sight_collision(map, pos1, pos2) == false) {
        for (int i = 0; i < 32; i++)
            map->fight->gui->points[i].color = sfBlack;
    } else
        default_line_color(map, weapon, get_index_npc(map->fight->turn_order,
            map->fight->target));
}

void compute_shoot_line(map_t *map, sfVector2f pos1,
    sfVector2f pos2)
{
    compute_shoot_line_pos(map->fight->gui, pos1, pos2);
    if (map->inventory->inventory->main_slots[12]->items != NULL)
        compute_shoot_line_color(map, pos1, pos2, map->inventory->inventory
            ->main_slots[12]->items->weapon);
    else
        compute_shoot_line_color(map, pos1, pos2, NULL);
}
