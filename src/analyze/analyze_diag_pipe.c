/*
** EPITECH PROJECT, 2024
** analyze_diag_pipe
** File description:
** analyze_diag_pipe
*/

#include "my.h"

void analyze_diag_pipe(game_t *game, diag_pipe_t *diag_pipe)
{
    if (diag_pipe->label != NULL && game->events->type == sfEvtKeyPressed &&
        game->events->key.code == game->keybinds->skip && (diag_pipe->answer ==
        NULL || *(diag_pipe->answer) == NULL)) {
        diag_pipe->close = sfTrue;
        if (diag_pipe->ll == NULL)
            *(diag_pipe->answer_loc) = -1;
    }
    if (diag_pipe->answer_btn != NULL) {
        for (int i = 0; diag_pipe->answer_btn[i] != NULL; i++)
            analyze_gui_obj(game->window, game->events,
                diag_pipe->answer_btn[i]);
    }
}
