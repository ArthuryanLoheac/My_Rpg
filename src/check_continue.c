/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to create a button
*/

#include "my.h"
#include "gui_struct.h"
#include <stdlib.h>

static int check_name(game_t *game)
{
    char *data = NULL;

    data = import_from_save("Name", game->savefilepath);
    if (data == NULL) {
        return 1;
    }
    return 0;
}

static int free_return(char **str_separated)
{
    free_array(str_separated);
    return 1;
}

static int check_class(game_t *game)
{
    char *data = import_from_save("Class", game->savefilepath);
    char **argss = my_str_to_word_array(data, "\n", 0);
    char *args;
    char **str_separated;

    if (data == NULL)
        return 1;
    args = argss[0];
    str_separated = my_str_to_word_array(args, ":", 0);
    if (my_pointlen(str_separated) != 2 || my_strlen(str_separated[1]) != 1)
        free_return(str_separated);
    if (str_separated[1][0] < '1' || str_separated[1][0] > '3')
        free_return(str_separated);
    if (strcmp(str_separated[0], "Class"))
        free_return(str_separated);
    free_array(str_separated);
    return 0;
}

static int check_gender(game_t *game)
{
    char *data = NULL;

    data = import_from_save("Gender", game->savefilepath);
    if (data == NULL)
        return 0;
    data = my_str_to_word_array(data, "\n", 63)[0];
    if (data == NULL)
        return 1;
    if (atoi(data) < 1 || atoi(data) > 2)
        return 1;
    return 0;
}

static int check_stats(game_t *game)
{
    char *data = import_from_save("Stats", game->savefilepath);
    char **args = my_str_to_word_array(data, "\n", 0);
    char **str_separated;
    int nb = 0;

    if (!data || !args)
        return 1;
    for (int i = 0; args[i]; i++) {
        str_separated = str_to_word_array(args[i], ":");
        nb = 0;
        if (my_pointlen(str_separated) != 2)
            return 1;
        nb = atoi(str_separated[1]);
        if (nb < 2)
            return 1;
    }
    return 0;
}

static int function(char **argss, char **elseing)
{
    if (atoi(argss[1]) >= 400 && atoi(argss[1]) < 500) {
        elseing = my_str_to_word_array(argss[1], ",", 0);
        if (!elseing || my_pointlen(elseing) != 2)
            return 1;
    }
    return 0;
}

static int function_trash(char **argss, char **elseing)
{
    if (atoi(argss[1]) >= 100 && atoi(argss[1]) < 200) {
        elseing = my_str_to_word_array(argss[1], ",", 0);
        if (!elseing || my_pointlen(elseing) != 2)
            return 1;
    }
    if (atoi(argss[1]) >= 200 && atoi(argss[1]) < 300) {
        elseing = my_str_to_word_array(argss[1], ",", 0);
        if (!elseing || my_pointlen(elseing) != 2)
            return 1;
    }
    if (atoi(argss[1]) >= 300 && atoi(argss[1]) < 400) {
        elseing = my_str_to_word_array(argss[1], ",", 0);
        if (!elseing || my_pointlen(elseing) != 5)
            return 1;
    }
    return function(argss, elseing);
}

static int check_inventory(game_t *game)
{
    char *data = import_from_save("Inventory", game->savefilepath);
    char **args = my_str_to_word_array(data, "\n\0", 0);
    char **elseing = NULL;
    char **argss = NULL;
    int returning = 0;

    for (int i = 0; returning == 0 && args[i]; i++) {
        argss = my_str_to_word_array(args[i], " :", 0);
        if (atoi(argss[0]) != i || i > 20)
            return 1;
        if (returning == 0 && argss && my_pointlen(argss) == 2 && (my_strcmp(
            argss[1], "0") != 0 && my_strcmp(argss[1], "null") != 0)) {
            returning = function_trash(argss, elseing);
        }
    }
    return returning;
}

static int last_check(game_t *game)
{
    int result = check_class(game) + check_name(game) +
        check_gender(game) + check_stats(game) + check_inventory(game);

    result += other_last_check(game);
    return result;
}

int check_here(char *file, game_t *game)
{
    if (!file)
        return -1;
    if (my_strcmpstart(file, "###Inventory") == -1 ||
        my_strcmpstart(file, "###Stats") == -1 ||
        my_strcmpstart(file, "###HP") == -1 ||
        my_strcmpstart(file, "###PLAYER") == -1 ||
        my_strcmpstart(file, "###Gender") == -1 ||
        my_strcmpstart(file, "###Name") == -1 ||
        my_strcmpstart(file, "###NPC") == -1 ||
        my_strcmpstart(file, "###Class") == -1 ||
        my_strcmpstart(file, "###Quest") == -1 ||
        my_strcmpstart(file, "###Map") == -1 ||
        my_strcmpstart(file, "###Time") == -1 ||
        my_strcmpstart(file, "###Money") == -1)
        return -1;
    if (last_check(game) > 0)
        return -1;
    return 0;
}
