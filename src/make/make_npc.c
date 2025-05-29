/*
** EPITECH PROJECT, 2024
** make_npc
** File description:
** make_npc, own function because it will probably be extened with weapon and
** armor displaying
*/

#include "my.h"

void make_npc(sfRenderWindow *window, npc_t *npc)
{
    linked_list_t *lst = npc->clothes;

    make_img(npc->npc, window);
    while (lst) {
        make_img(lst->data, window);
        lst = lst->next;
    }
}
