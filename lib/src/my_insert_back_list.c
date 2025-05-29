/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** add an element into a linked list at its last position
*/

#include <stdlib.h>
#include "../include/lib.h"

int my_insert_back_list(struct linked_list **list, void *elt)
{
    struct linked_list *new = malloc(sizeof(*new));
    linked_list_t *list_ptr = *list;

    new->data = elt;
    new->next = NULL;
    if (*list == NULL) {
        *list = new;
        new->prev = NULL;
        return 0;
    }
    while (list_ptr->next != NULL)
        list_ptr = list_ptr->next;
    list_ptr->next = new;
    new->prev = list_ptr;
    return 0;
}
