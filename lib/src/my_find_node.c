/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** find and return a pointer to the first structure with
** same data as provided
*/

#include <stdlib.h>
#include "../include/lib.h"

linked_list_t *my_find_node(
    linked_list_t const *begin,
    void const *data_ref,
    int (*cmp)())
{
    struct linked_list *list_ptr;

    list_ptr = (linked_list_t *)begin;
    while (list_ptr != NULL) {
        if ((*cmp)(list_ptr->data, data_ref) == 0)
            return (list_ptr);
        list_ptr = list_ptr->next;
    }
    return 0;
}
