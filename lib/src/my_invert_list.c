/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** swap an element into a linked list
*/

#include <stdlib.h>
#include "../include/lib.h"

int my_invert_list_next(struct linked_list *list)
{
    void *temp;

    if (list->next != NULL) {
        temp = list->data;
        list->data = list->next->data;
        list->next->data = temp;
    } else {
        return 1;
    }
    return 0;
}

int my_invert_list_prev(struct linked_list *list)
{
    void *temp;

    if (list->prev != NULL) {
        temp = list->data;
        list->data = list->prev->data;
        list->prev->data = temp;
    } else {
        return 1;
    }
    return 0;
}
