/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** return the number of element in a linked list
*/

#include <stdlib.h>
#include "../include/lib.h"

int linked_list_len(linked_list_t **entity)
{
    linked_list_t *element = *entity;
    int i = 0;

    while (element) {
        element = element->next;
        i++;
    }
    return i;
}

int my_list_size(linked_list_t const *begin)
{
    struct linked_list const *temp;
    int count = 0;

    temp = begin;
    while (temp != NULL && temp->prev != NULL) {
        temp = temp->prev;
    }
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
