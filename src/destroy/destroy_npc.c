/*
** EPITECH PROJECT, 2024
** destroy_npc
** File description:
** destroy_npc
*/

#include "my.h"

void destroy_npc(npc_t *npc)
{
    linked_list_t *clothes = npc->clothes;

    destroy_image(npc->npc);
    destroy_time(npc->own_clock);
    if (npc->name != NULL)
        free(npc->name);
    while (clothes) {
        destroy_image(clothes->data);
        clothes = clothes->next;
    }
}
