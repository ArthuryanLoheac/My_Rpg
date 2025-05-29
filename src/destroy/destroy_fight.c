/*
** EPITECH PROJECT, 2024
** destroy_fight
** File description:
** destroy_fight
*/

#include "my.h"

void destroy_new_game_fight(fight_t *fight)
{
    destroy_fight_gui(fight->gui);
    free(fight);
}
