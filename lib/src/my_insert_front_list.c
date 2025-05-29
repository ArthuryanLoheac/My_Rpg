/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** add an element into a linked list at its first position
*/

#include <stdlib.h>
#include "../include/lib.h"

int my_insert_front_list(struct linked_list **list, void *elt)
{
    struct linked_list *new = malloc(sizeof(*new));

    new->data = elt;
    new->next = *list;
    new->prev = NULL;
    *list = new;
    return 0;
}
