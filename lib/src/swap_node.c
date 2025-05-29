/*
** EPITECH PROJECT, 2024
** swap node
** File description:
** swap_node
*/

#include "../include/my.h"

void swap_node(linked_list_t *first,
    linked_list_t *second, linked_list_t **entity)
{
    linked_list_t *next = second->next;
    linked_list_t *prev = first->prev;

    if (prev)
        prev->next = second;
    second->prev = prev;
    second->next = first;
    first->prev = second;
    first->next = next;
    if (next)
        next->prev = first;
    if (*entity == first)
        *entity = second;
}
