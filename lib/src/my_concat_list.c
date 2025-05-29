/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** link two linked list together
*/

#include <stdlib.h>
#include "../include/lib.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    struct linked_list *list_ptr;

    list_ptr = *begin1;
    while (list_ptr->next != NULL) {
        list_ptr = list_ptr->next;
    }
    list_ptr->next = begin2;
}
