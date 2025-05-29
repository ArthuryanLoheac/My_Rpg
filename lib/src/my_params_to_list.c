/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** make a linked list out of the provided arguments,
** in reverse order in which they were given but
** inserting them in the order in which they were given
*/

#include <stdlib.h>
#include "../include/lib.h"

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    struct linked_list *list;

    list = NULL;
    for (int i = 0; i != ac; i++) {
        my_insert_front_list(&list, av[i]);
    }
    return list;
}
