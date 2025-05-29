/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** apply a function to all the data
** of every nodes matching data_ref in a list
*/

#include <stdlib.h>
#include "../include/lib.h"

int my_apply_on_matching_nodes(
    linked_list_t *begin,
    int (*f)(),
    void const *data_ref,
    int (*cmp)())
{
    struct linked_list *list_ptr;

    list_ptr = begin;
    while (list_ptr != NULL) {
        if ((*cmp)(list_ptr->data, data_ref) == 0)
            (*f)(list_ptr->data);
        list_ptr = list_ptr->next;
    }
    return 0;
}
