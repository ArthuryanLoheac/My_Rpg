/*
** EPITECH PROJECT, 2024
** destroy_entity
** File description:
** destroy_entity
*/

#include "my.h"

void destroy_civilian(civ_t *civ)
{
    linked_list_t *clothes = civ->clothes;

    destroy_image(civ->civ);
    destroy_time(civ->own_clock);
    while (clothes) {
        destroy_image(clothes->data);
        clothes = clothes->next;
    }
}
