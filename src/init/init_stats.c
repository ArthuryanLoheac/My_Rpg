/*
** EPITECH PROJECT, 2024
** init_stats
** File description:
** init_stats
*/
#include "my.h"

static void default_stats(stats_t *stats)
{
    stats->BODY = 0;
    stats->EMP = 0;
    stats->LUCK = 0;
    stats->MOVE = 0;
    stats->REF = 0;
    stats->TECH = 0;
    stats->WILL = 0;
    stats->DEX = 0;
    stats->HUM = 0;
}

static void assign_value_stat(char *stat, int nb, stats_t *stats)
{
    if (!my_strcmp(stat, "MOVE"))
        stats->MOVE = nb;
    if (!my_strcmp(stat, "TECH"))
        stats->TECH = nb;
    if (!my_strcmp(stat, "WILL"))
        stats->WILL = nb;
    if (!my_strcmp(stat, "BODY"))
        stats->BODY = nb;
    if (!my_strcmp(stat, "REF"))
        stats->REF = nb;
    if (!my_strcmp(stat, "DEX"))
        stats->DEX = nb;
    if (!my_strcmp(stat, "EMP"))
        stats->EMP = nb;
    if (!my_strcmp(stat, "LUCK"))
        stats->LUCK = nb;
    if (!my_strcmp(stat, "HUM"))
        stats->HUM = nb;
}

static void check_stat_line(char *str, stats_t *stats)
{
    char **str_separated = str_to_word_array(str, ":");
    int nb = 0;

    if (my_pointlen(str_separated) != 2)
        return;
    nb = atoi(str_separated[1]);
    assign_value_stat(str_separated[0], nb, stats);
}

static void load_stats(game_t *game, stats_t *stats)
{
    char *data = import_from_save("Stats", game->savefilepath);
    char **args = my_str_to_word_array(data, "\n", 0);

    default_stats(stats);
    for (int i = 0; args[i]; i++) {
        check_stat_line(args[i], stats);
    }
}

stats_t *init_stats(game_t *game, bool new_game)
{
    stats_t *stats = malloc(sizeof(stats_t));

    if (!game || game->savefile == -1 || new_game)
        default_stats(stats);
    else
        load_stats(game, stats);
    return stats;
}

stats_t *init_stats2(int *data)
{
    stats_t *stats = malloc(sizeof(stats_t));

    stats->BODY = data[0];
    stats->EMP = data[1];
    stats->LUCK = data[2];
    stats->MOVE = data[3];
    stats->REF = data[4];
    stats->TECH = data[5];
    stats->WILL = data[6];
    stats->DEX = data[7];
    stats->HUM = stats->EMP * 10;
    return stats;
}
