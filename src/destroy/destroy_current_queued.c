/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to destroy the game struct
*/

#include "my.h"

void destroy_current_queued(diag_pipe_t *diag_pipe)
{
    linked_list_t *temp;

    free(((diag_queue_t *)(diag_pipe->ll->data))->text);
    free(((diag_queue_t *)(diag_pipe->ll->data))->name);
    free(diag_pipe->ll->data);
    temp = diag_pipe->ll;
    diag_pipe->ll = diag_pipe->ll->next;
    free(temp);
}
