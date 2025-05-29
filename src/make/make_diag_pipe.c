/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to display a message
*/

#include "my.h"

void make_diag_pipe(sfRenderWindow *window, diag_pipe_t *diag_pipe)
{
    if (diag_pipe->clock != NULL) {
        make_img(diag_pipe->background, window);
        make_img(diag_pipe->portrait, window);
        sfRenderWindow_drawText(window, diag_pipe->label->txt, NULL);
        sfRenderWindow_drawText(window, diag_pipe->label_n->txt, NULL);
        for (int i = 0; diag_pipe->answer_btn[i] != NULL; i++)
            make_gui_obj(window, diag_pipe->answer_btn[i], sfTransparent);
    }
}
