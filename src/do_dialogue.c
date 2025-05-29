/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** rule 1 dont leave a newline at the end of dialogue file
** rule 2 do not free anything
*/

#include "my.h"

static int *init_answer_loc(int *answer_loc)
{
    answer_loc = malloc(sizeof(int));
    *answer_loc = 0;
    return answer_loc;
}

static int destroy_answer_loc(int *answer_loc, int *step)
{
    *step = 0;
    *answer_loc = 0;
    return 0;
}

int do_dialogue(char *id, map_t *map)
{
    static int step = 0;
    static int *answer_loc = NULL;

    if (answer_loc == NULL)
        answer_loc = init_answer_loc(answer_loc);
    if (step == 0) {
        send_script(append_str(id, ".diag"),
            map->portrait, map->dialogue_pipeline, answer_loc);
        step++;
    }
    if (step == 2 || *answer_loc == -1)
        return destroy_answer_loc(answer_loc, &step);
    if (step == 1 && *answer_loc != 0) {
        send_script(append_str2(append_str2(my_strdup(id),
            int_to_str(*answer_loc)), my_strdup(".diag")),
            map->portrait, map->dialogue_pipeline, answer_loc);
        step++;
    }
    return 1;
}

void compute_dialogue(map_t *map)
{
    static int i = 0;

    if (map->dialogue == NULL)
        return;
    if (map->dialogue[i] != NULL) {
        if (do_dialogue(map->dialogue[i], map) == 0) {
            free(map->dialogue[i]);
            i++;
        }
    } else {
        free(map->dialogue);
        i = 0;
        map->dialogue = NULL;
    }
}
