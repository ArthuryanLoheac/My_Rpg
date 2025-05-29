/*
** EPITECH PROJECT, 2024
** init_map
** File description:
** init_map
*/

#include "my.h"

diag_pipe_t *init_diag_pipe(assets_t **assets)
{
    diag_pipe_t *diag_pipe = malloc(sizeof(diag_pipe_t));

    diag_pipe->clock = NULL;
    diag_pipe->label = NULL;
    diag_pipe->label_n = NULL;
    diag_pipe->close = sfTrue;
    diag_pipe->text = NULL;
    diag_pipe->background = init_image(get_asset("dialog_box", assets),
        (sfVector2f){20, 730}, 1.4);
    diag_pipe->portrait = NULL;
    diag_pipe->ll = NULL;
    diag_pipe->answer_btn = NULL;
    diag_pipe->answer = NULL;
    diag_pipe->answer_loc = NULL;
    diag_pipe->answer_bg = init_image(get_asset("answer_box", assets),
        vect0(), 1.2);
    return diag_pipe;
}
