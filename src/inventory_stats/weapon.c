/*
** EPITECH PROJECT, 2024
** weapons stats
** File description:
** weapons
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

static void set_melee_weapons_stats_part2(item_t *item)
{
    if (item->id % 100 == 12) {
        item->weapon->ammo_type_e = MELEE;
        item->weapon->type = KATANA;
        item->weapon->magazine = (sfVector2i) {0, 0};
        item->weapon->durability.y = 10;
        item->weapon->durability.x = 10;
        item->weapon->damagd6 = 3;
        item->weapon->rof = 1;
    }
    if (item->id % 100 == 13) {
        item->weapon->ammo_type_e = MELEE;
        item->weapon->type = HELICO_BLADES;
        item->weapon->magazine = (sfVector2i) {0, 0};
        item->weapon->durability.y = 10;
        item->weapon->durability.x = 10;
        item->weapon->damagd6 = 4;
        item->weapon->rof = 1;
    }
}

static void set_melee_weapons_stats(item_t *item)
{
    if (item->id % 100 == 10) {
        item->weapon->ammo_type_e = MELEE;
        item->weapon->type = KNIFE;
        item->weapon->magazine = (sfVector2i) {0, 0};
        item->weapon->durability.y = 10;
        item->weapon->damagd6 = 1;
        item->weapon->rof = 3;
    }
    if (item->id % 100 == 11) {
        item->weapon->ammo_type_e = MELEE;
        item->weapon->type = TOMAHAWK;
        item->weapon->magazine = (sfVector2i) {0, 0};
        item->weapon->durability.y = 10;
        item->weapon->damagd6 = 2;
        item->weapon->rof = 2;
    }
    set_melee_weapons_stats_part2(item);
}

static void set_pistol_stats(item_t *item, int *data)
{
    if (item->id % 100 == 1) {
        item->weapon->ammo_type_e = HANDGUN;
        item->weapon->magazine = (sfVector2i) {data[0], 12};
        item->weapon->damagd6 = 2;
        item->weapon->rof = 2;
    }
    if (item->id % 100 == 2) {
        item->weapon->ammo_type_e = HANDGUN;
        item->weapon->magazine = (sfVector2i) {8, 8};
        item->weapon->damagd6 = 4;
        item->weapon->rof = 1;
    }
    if (item->id % 100 >= 1 && item->id % 100 <= 2)
        item->weapon->opt_distance = 150;
}

static void set_short_ranged_stats(item_t *item, int *data)
{
    if (item->id % 100 == 3) {
        item->weapon->ammo_type_e = HANDGUN;
        item->weapon->magazine = (sfVector2i) {30, 30};
        item->weapon->damagd6 = 2;
        item->weapon->opt_distance = 225;
    }
    if (item->id % 100 == 4) {
        item->weapon->ammo_type_e = SLUGS;
        item->weapon->magazine = (sfVector2i) {data[0], 4};
        item->weapon->damagd6 = 5;
        item->weapon->opt_distance = 150;
    }
    if (item->id % 100 == 5) {
        item->weapon->ammo_type_e = SHOULDER_ARM;
        item->weapon->magazine = (sfVector2i) {data[0], 25};
        item->weapon->damagd6 = 5;
        item->weapon->opt_distance = 850;
    }
    if (item->id % 100 >= 3 && item->id % 100 <= 5)
        item->weapon->rof = 1;
}

static void set_long_range_stats(item_t *item, int *data)
{
    if (item->id % 100 == 6) {
        item->weapon->ammo_type_e = SHOULDER_ARM;
        item->weapon->magazine = (sfVector2i) {data[0], 4};
        item->weapon->damagd6 = 6;
        item->weapon->opt_distance = 1300;
    }
    if (item->id % 100 == 7) {
        item->weapon->ammo_type_e = HEAVY;
        item->weapon->magazine = (sfVector2i) {data[0], 1};
        item->weapon->damagd6 = 8;
        item->weapon->opt_distance = 550;
    }
    if (item->id % 100 == 8) {
        item->weapon->ammo_type_e = HEAVY;
        item->weapon->magazine = (sfVector2i) {data[0], 2};
        item->weapon->damagd6 = 6;
        item->weapon->opt_distance = 400;
    }
    if (item->id % 100 >= 6 && item->id % 100 <= 8)
        item->weapon->rof = 1;
}

static void set_bow_stats(item_t *item)
{
    if (item->id % 100 == 9) {
        item->weapon->ammo_type_e = ARCHERY;
        item->weapon->magazine = (sfVector2i) {0, 0};
        item->weapon->durability.y = 100;
        item->weapon->damagd6 = 4;
        item->weapon->rof = 1;
        item->weapon->opt_distance = 450;
    }
}

void set_weapon_stats(item_t *item, int *data)
{
    if (item->type == WEAPON) {
        item->weapon = malloc(sizeof(weapon_t));
        set_pistol_stats(item, data);
        set_short_ranged_stats(item, data);
        set_long_range_stats(item, data);
        item->weapon->durability = (sfVector2i) {data[1],
            item->weapon->magazine.y * 20};
        item->weapon->mods = (sfVector2i) {0, 3};
        item->weapon->bonus_tohit = data[2];
        item->weapon->bonus_damage = data[3];
        item->weapon->type = item->id % 100;
        set_bow_stats(item);
        set_melee_weapons_stats(item);
        if (data[1] == 99999)
            item->weapon->durability.x = item->weapon->durability.y;
        if (data[0] == 99)
            item->weapon->magazine.x = item->weapon->magazine.y;
    }
}
