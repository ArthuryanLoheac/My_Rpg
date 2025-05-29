/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** show a linked list of the linked list type
*/
#include <stdlib.h>
#include "../include/lib.h"

void my_show_linked_list(struct linked_list *list)
{
    struct linked_list *temp;

    temp = list;
    while (temp != NULL) {
        my_putstr(temp->data);
        my_putchar('\n');
        temp = temp->next;
    }
}
