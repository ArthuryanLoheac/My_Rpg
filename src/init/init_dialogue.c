/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** the main file
*/

#include "my.h"

static char *remove_and_replace(char *replace_by, int i, char *str)
{
    char *tmp1;
    char *tmp;

    str = remove_stri(str, i);
    str = remove_stri(str, i);
    tmp = my_strdup(&str[i]);
    tmp1 = my_strndup(str, i);
    free(str);
    return append_str2(tmp1, append_str2(
        my_strdup(replace_by), tmp));
}

static char *set_name_in_text(char *str, char *name, int gender)
{
    char *alter = my_strdup("Mustang");

    if (gender == 2)
        alter = my_strdup("Darrow");
    for (int i = 0; i < my_strlen(str) - 1; i++) {
        if (str[i] == 'Z' && str[i + 1] == 'n')
            return set_name_in_text(remove_and_replace(name, i, str),
                name, gender);
        if (str[i] == 'N' && str[i + 1] == 'z')
            return set_name_in_text(remove_and_replace(alter, i, str),
                name, gender);
    }
    return str;
}

static char *set_name(char *str, char *name)
{
    if (my_strcmp(str, "protagonist") == 0)
        return my_strdup(name);
    return my_strdup(str);
}

void init_dialogue(diag_queue_t *diag_q, diag_pipe_t *dialogue_pipeline,
    char *pc_name, int gender)
{
    char *cpy = my_strdup(diag_q->text);
    char **res = my_str_to_word_array(cpy, ";", 0);
    sfFloatRect rect =
        sfSprite_getGlobalBounds(dialogue_pipeline->background->sprite);
    sfFloatRect rect2;

    dialogue_pipeline->clock = init_time();
    dialogue_pipeline->text = set_name_in_text(res[0], pc_name, gender);
    dialogue_pipeline->name = set_name(diag_q->name, pc_name);
    dialogue_pipeline->close = sfFalse;
    dialogue_pipeline->portrait = diag_q->portrait;
    dialogue_pipeline->answer = &res[1];
    dialogue_pipeline->answer_loc = diag_q->answer_loc;
    sfSprite_setPosition(dialogue_pipeline->portrait->sprite, (sfVector2f){65,
        770});
    rect2 = sfSprite_getLocalBounds(dialogue_pipeline->portrait->sprite);
    sfSprite_setScale(dialogue_pipeline->portrait->sprite, (sfVector2f){
        (rect.height - 95) / rect2.height, (rect.height - 95) / rect2.height});
    free(cpy);
}
