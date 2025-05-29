/*
** EPITECH PROJECT, 2024
** stats
** File description:
** stats
*/

#pragma once
#include <stdarg.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "struct.h"
#include "struct_prototype.h"

void set_ammo_stats(item_t *item, int nbr_bullets);
void set_armor_stats(item_t *item, int current);
void set_weapon_stats(item_t *item, int *data);
void set_gear_stats(item_t *item);
void set_drugs_stats(item_t *item, int nbr_bullets);
void set_cyberware_stats(item_t *item, int value);
