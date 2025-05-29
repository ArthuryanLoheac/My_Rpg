/*
** EPITECH PROJECT, 2024
** init_stats
** File description:
** init_stats
*/
#include "my.h"

static void check_stat_line(char *str, enum class_e *stats)
{
    char **str_separated = my_str_to_word_array(str, ":", 0);

    if (my_pointlen(str_separated) != 2 || my_strlen(str_separated[1]) != 1) {
        free_array(str_separated);
        return;
    }
    if (str_separated[1][0] < '1' || str_separated[1][0] > '3') {
        free_array(str_separated);
        return;
    }
    if (strcmp(str_separated[0], "Class")) {
        free_array(str_separated);
        return;
    }
    *stats = (enum class_e)(str_separated[1][0] - '0');
    free_array(str_separated);
}

static void load_stats(game_t *game, enum class_e *stats)
{
    char *data = import_from_save("Class", game->savefilepath);
    char *args = my_str_to_word_array(data, "\n", 0)[0];

    check_stat_line(args, stats);
}

enum class_e init_class(game_t *game)
{
    enum class_e class = NO_CLASS;

    if (!game || game->savefile == -1)
        return class;
    else
        load_stats(game, &class);
    return class;
}
