/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** apply a function to all the data
** of each nodes in a list
*/

#include <stdlib.h>
#include "../include/lib.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    struct linked_list *list_ptr;

    list_ptr = begin;
    while (list_ptr != NULL) {
        (*f)(list_ptr->data);
        list_ptr = list_ptr->next;
    }
    return 0;
}
