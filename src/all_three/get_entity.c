/*
** EPITECH PROJECT, 2023
** my
** File description:
** our own version of printf
*/

#include "my.h"

void set_scatter_shown(int id, linked_list_t *entity)
{
    while (entity) {
        if (((entity_t *)(entity->data))->type == SCATTER &&
            ((entity_t *)(entity->data))->scatter->id == id) {
            ((entity_t *)(entity->data))->hidden = false;
            }
        entity = entity->next;
    }
}

entity_t *get_scatter(int id, linked_list_t *entity)
{
    while (entity) {
        if (((entity_t *)(entity->data))->type == SCATTER &&
            ((entity_t *)(entity->data))->scatter->id == id) {
            return ((entity_t *)(entity->data));
            }
        entity = entity->next;
    }
    return NULL;
}

int get_pc_index(linked_list_t *entity)
{
    int i = 0;

    while (entity != NULL) {
        if (((entity_t *)(entity->data))->type == PC) {
            return i;
            }
        entity = entity->next;
        i++;
    }
    return -1;
}
