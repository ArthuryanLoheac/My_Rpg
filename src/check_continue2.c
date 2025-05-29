/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to create a button
*/

#include "my.h"
#include "gui_struct.h"
#include <stdlib.h>

static int check_hp(game_t *game)
{
    char *str = import_from_save("HP", game->savefilepath);
    char **str_separated;

    str = my_str_to_word_array(str, "\n", 0)[0];
    str_separated = str_to_word_array(str, ":");
    if (my_pointlen(str_separated) != 2)
        return 1;
    for (int i = 0; i < my_strlen(str_separated[0]); i++) {
        if (str_separated[0][i] < '0' || str_separated[0][i] > '9')
            return 1;
    }
    for (int i = 0; i < my_strlen(str_separated[1]); i++) {
        if (str_separated[1][i] < '0' || str_separated[1][i] > '9')
            return 1;
    }
    return 0;
}

static int check_quest(game_t *game)
{
    char **res = my_str_to_word_array(import_from_save("Quest",
        game->savefilepath), "\n", 0);

    if (res == NULL)
        return 1;
    if (my_pointlen(res) != 2 || (my_getnbr(res[1]) == 0 && res[1][0] != '0'))
        return 1;
    if (my_getnbr(res[1]) < 0)
        return 1;
    free_array(res);
    return 0;
}

static int check_money(game_t *game)
{
    char *data = NULL;

    data = import_from_save("Money", game->savefilepath);
    if (data == NULL)
        return 1;
    data = my_str_to_word_array(data, "\n", 63)[0];
    if (atoi(data) < 0)
        return 1;
    return 0;
}

static int check_map(game_t *game)
{
    char *data = NULL;

    data = import_from_save("Map", game->savefilepath);
    if (data == NULL)
        return 1;
    return 0;
}

static int check_pos(game_t *game)
{
    char *data_save = NULL;
    char **data = NULL;
    char **data_pos;

    data_save = import_from_save("PLAYER", game->savefilepath);
    if (my_strlen(data_save) == 0)
        return 1;
    data = str_to_word_array(data_save, " \n");
    if (my_pointlen(data) != 2)
        return 1;
    data_pos = str_to_word_array(data[0], ",");
    if (my_pointlen(data_pos) != 2)
        return 1;
    if (atof(data_pos[0]) < 0 || atof(data_pos[1]) < 0)
        return 1;
    return 0;
}

static int check_xp(game_t *game)
{
    char *data_save = import_from_save("PLAYER", game->savefilepath);
    char **data;
    int nbr_len;
    char **data_level;

    if (!data_save || my_strlen(data_save) == 0)
        return 1;
    data = str_to_word_array(data_save, " \n");
    nbr_len = my_pointlen(data);
    if (nbr_len == 2) {
        data_level = str_to_word_array(data[1], ",");
        if (my_pointlen(data_level) != 2)
            return 1;
    } else
        return 1;
    return 0;
}

static int check_time(game_t *game)
{
    char *data = NULL;

    data = import_from_save("Time", game->savefilepath);
    if (data == NULL)
        return 1;
    data = my_str_to_word_array(data, "\n", 63)[0];
    if (atoi(data) < 0)
        return 1;
    return 0;
}

int other_last_check(game_t *game)
{
    int result = check_quest(game) + check_time(game) + check_xp(game) +
        check_money(game) + check_pos(game) + check_map(game) + check_hp(game);

    return result;
}
