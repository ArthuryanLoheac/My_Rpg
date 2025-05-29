/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** delete the current node in a double linked list
*/

#include <stdlib.h>
#include "../include/lib.h"

int my_del_list_current(linked_list_t **begin)
{
    linked_list_t *ll = *begin;

    if (ll->next == NULL && ll->prev == NULL)
        return 1;
    if (ll->next == NULL) {
        *begin = ll->prev;
        ll->prev->next = NULL;
        return 0;
    }
    if (ll->prev == NULL) {
        *begin = ll->next;
        ll->next->prev = NULL;
        return 0;
    }
    ll->next->prev = ll->prev;
    ll->prev->next = ll->next;
    *begin = ll->next;
    return 0;
}
