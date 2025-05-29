/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to create a queue_diag
*/

#include "my.h"

diag_queue_t *init_queue_diag(char *txt, img_t *portrait, int *answer_loc,
    char *name)
{
    diag_queue_t *diag_queue = malloc(sizeof(diag_pipe_t));

    diag_queue->portrait = portrait;
    diag_queue->text = txt;
    diag_queue->answer_loc = answer_loc;
    diag_queue->name = name;
    return diag_queue;
}
