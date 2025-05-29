/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to compute a message
*/

#include "my.h"

int my_pointlen2(gui_obj_t **str)
{
    int i;

    i = 0;
    while (str[i] != NULL) {
        i++;
    }
    return (i);
}

void compute_answer(diag_pipe_t *diag_pipe)
{
    for (int i = 0; diag_pipe->answer_btn[i] != NULL; i++) {
        if (diag_pipe->answer_btn[i]->state == HOVER)
            sfSprite_setColor(diag_pipe->answer_btn[i]->img->sprite, sfRed);
        if (diag_pipe->answer_btn[i]->state == PRESSED)
            sfSprite_setColor(diag_pipe->answer_btn[i]->img->sprite, sfBlack);
        if (diag_pipe->answer_btn[i]->state == NO_STATE)
            sfSprite_setColor(diag_pipe->answer_btn[i]->img->sprite, sfWhite);
        if (diag_pipe->answer_btn[i]->state == RELEASED &&
            my_pointlen2(diag_pipe->answer_btn) != 1) {
            diag_pipe->close = sfTrue;
            *(diag_pipe->answer_loc) = i + 1;
        }
        if (diag_pipe->answer_btn[i]->state == RELEASED &&
            my_pointlen2(diag_pipe->answer_btn) == 1) {
            diag_pipe->close = sfTrue;
            *(diag_pipe->answer_loc) = -1;
        }
    }
}
