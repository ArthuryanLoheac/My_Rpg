/*
** EPITECH PROJECT, 2024
** quest
** File description:
** init_quest
*/

#include "my.h"

quest_t *continue_quest(game_t *game)
{
    quest_t *quest;
    char **res = my_str_to_word_array(import_from_save("Quest",
        game->savefilepath), "\n", 0);

    if (my_pointlen(res) != 2 || (my_getnbr(res[1]) == 0 && res[1][0] != '0'))
        wrong_savefile(game->savefilepath, "###Quest");
    quest = init_quest(res[0], my_getnbr(res[1]));
    free_array(res);
    if (!quest)
        wrong_savefile(game->savefilepath, "###Quest");
    return quest;
}

quest_t *init_quest(char *name, int progression)
{
    if (my_strcmp(name, "Citizen Erazed") == 0)
        return init_citizen_erazed(progression);
    if (my_strcmp(name, "Thought Contagion") == 0)
        return init_thought_contagion(progression);
    return NULL;
}
