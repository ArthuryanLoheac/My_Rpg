/*
** EPITECH PROJECT, 2023
** my
** File description:
** our own version of printf
*/

#pragma once
#include "my.h"

#define MONEY_EARN 200

void quest_increase1(game_t *game, map_t *map);
void quest_increase2(game_t *game, map_t *map);
void quest_increase3(game_t *game, map_t *map);

bool empty_diag(map_t *map);
bool is_in_fight(char *name, linked_list_t *entity);
char **diag(char *prefix, char *diags);
sfVector2f *vector(float x, float y);
quest_t *init_citizen_erazed(int progression);
void compute_citizen_erazed_1(quest_t *quest, map_t *map, game_t *game);
void compute_citizen_erazed_2(quest_t *quest, map_t *map, game_t *game);
void compute_citizen_erazed_3(quest_t *quest, map_t *map, game_t *game);
void compute_citizen_erazed_4(quest_t *quest, map_t *map, game_t *game);
quest_t *init_thought_contagion(int progression);
char *init_citizen_erazed_obj(int prog);
char *init_thought_contagion_obj(int prog);
void compute_thought_contagion(quest_t *quest, map_t *map, game_t *game);
void compute_citizen_erazed(quest_t *quest, map_t *map, game_t *game);
