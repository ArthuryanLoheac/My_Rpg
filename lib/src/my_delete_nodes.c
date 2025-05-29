/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** find and delete all corresponding nodes in a list
*/

#include <stdlib.h>
#include "../include/lib.h"

int my_delete_nodes(
    linked_list_t **begin,
    void const *data_ref,
    int (*cmp)())
{
    struct linked_list *list_ptr;

    list_ptr = *begin;
    if ((*cmp)(list_ptr->data, data_ref) == 0) {
        *begin = list_ptr->next;
    }
    while (list_ptr->next != NULL) {
        if ((*cmp)(list_ptr->next->data, data_ref) == 0) {
            list_ptr->next = list_ptr->next->next;
            return 0;
        }
        list_ptr = list_ptr->next;
    }
    return 84;
}

static void delete_node(struct linked_list *list_ptr)
{
    list_ptr->prev->next = list_ptr->next;
    if (list_ptr->next != NULL) {
        list_ptr->next->prev = list_ptr->prev;
    }
}

int my_delete_nodes2(
    linked_list_t **begin, int index)
{
    struct linked_list *list_ptr;
    int i = 0;

    list_ptr = *begin;
    if (index == 0) {
        *begin = list_ptr->next;
        if (*begin != NULL) {
            (*begin)->prev = NULL;
        }
        return 0;
    }
    while (list_ptr != NULL) {
        if (i == index) {
            delete_node(list_ptr);
        }
        list_ptr = list_ptr->next;
        i++;
    }
    return 84;
}
