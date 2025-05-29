/*
** EPITECH PROJECT, 2024
** init_stats
** File description:
** init_stats
*/
#include "my.h"

static void default_hp(sfVector2i *stats)
{
    stats->x = 10;
    stats->y = 20;
}

static void check_hp_line(char *str, sfVector2i *stats)
{
    char **str_separated = str_to_word_array(str, ":");

    if (my_pointlen(str_separated) != 2)
        return;
    for (int i = 0; i < my_strlen(str_separated[0]); i++) {
        if (str_separated[0][i] < '0' || str_separated[0][i] > '9')
            return;
    }
    for (int i = 0; i < my_strlen(str_separated[1]); i++) {
        if (str_separated[1][i] < '0' || str_separated[1][i] > '9')
            return;
    }
    stats->x = my_getnbr(str_separated[0]);
    stats->y = my_getnbr(str_separated[1]);
}

static void load_hp(game_t *game, sfVector2i *stats)
{
    char *str = import_from_save("HP", game->savefilepath);

    str = my_str_to_word_array(str, "\n", 0)[0];
    check_hp_line(str, stats);
}

sfVector2i *init_hp(game_t *game)
{
    sfVector2i *stats = malloc(sizeof(sfVector2i));

    if (!game || game->savefile == -1)
        default_hp(stats);
    else
        load_hp(game, stats);
    return stats;
}
