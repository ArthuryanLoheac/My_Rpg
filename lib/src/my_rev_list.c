/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** reverse a linked list
*/

#include <stdlib.h>
#include "../include/lib.h"

void my_rev_list(linked_list_t **begin)
{
    int size = my_list_size(*begin);
    struct linked_list *temp;
    struct linked_list *addressone;
    struct linked_list *addresstwo;

    addressone = *begin;
    addresstwo = NULL;
    for (int i = 0; i != size - 1; i++) {
        temp = addresstwo;
        addresstwo = addressone->next;
        addressone->next = temp;
        temp = addresstwo;
        addresstwo = addressone;
        addressone = temp;
    }
    addressone->next = addresstwo;
    *begin = addressone;
}
