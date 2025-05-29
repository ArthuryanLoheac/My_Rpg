/*
** EPITECH PROJECT, 2024
** compute_recap_shop
** File description:
** compute_recap_shop
*/

#include "my.h"
#include "gui_struct.h"

static void compute_text_solo(char *str, stats_t *stats)
{
    sprintf(str, "\t\t-- SOLO --\n\nDex : "
    "\t%d\tTech : \t%d\n\nMov : \t%d\tBody : "
    "\t%d\n\nRef : \t%d\tWill : \t%d\n\nEmp :"
    " \t%d\tLuck : \t%d\n\nHum : \t%d",
        stats->DEX, stats->TECH, stats->MOVE, stats->BODY, stats->REF,
        stats->WILL, stats->EMP, stats->LUCK, stats->HUM);
}

static void compute_text_tech(char *str, stats_t *stats)
{
    sprintf(str, "\t\t-- TECH --\n\nDex"
    " : \t%d\tTech : \t%d\n\nMov : \t%d\tBody : "
    "\t%d\n\nRef : \t%d\tWill : \t%d\n\nEmp :"
    " \t%d\tLuck : \t%d\n\nHum : \t%d",
        stats->DEX, stats->TECH, stats->MOVE, stats->BODY, stats->REF,
        stats->WILL, stats->EMP, stats->LUCK, stats->HUM);
}

static void compute_text_medtech(char *str, stats_t *stats)
{
    sprintf(str, "\t\t-- MEDTECH --\n\nDex :"
    " \t%d\tTech : \t%d\n\nMov : \t%d\tBody : "
    "\t%d\n\nRef : \t%d\tWill : \t%d\n\nEmp :"
    " \t%d\tLuck : \t%d\n\nHum : \t%d",
        stats->DEX, stats->TECH, stats->MOVE, stats->BODY, stats->REF,
        stats->WILL, stats->EMP, stats->LUCK, stats->HUM);
}

void compute_recap_shop(recap_t *recap, player_character_t *player,
    stats_t *stats)
{
    char str[200];

    if (player->class == SOLO)
        compute_text_solo(str, stats);
    if (player->class == TECH)
        compute_text_tech(str, stats);
    if (player->class == MED)
        compute_text_medtech(str, stats);
    sfText_setString(recap->Class->txt, str);
}
