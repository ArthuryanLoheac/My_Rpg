/*
** EPITECH PROJECT, 2023
** my
** File description:
** our own version of printf
*/

#include "my.h"

npc_t *get_npc(char *name, linked_list_t *entity)
{
    while (entity != NULL) {
        if (((entity_t *)(entity->data))->type == NPC &&
            my_strcmp(((entity_t *)(entity->data))->npc->name, name) == 0) {
            return ((entity_t *)(entity->data))->npc;
        }
        entity = entity->next;
    }
    return NULL;
}

entity_t *get_npc2(char *name, linked_list_t *entity)
{
    while (entity != NULL) {
        if (((entity_t *)(entity->data))->type == NPC &&
            my_strcmp(((entity_t *)(entity->data))->npc->name, name) == 0) {
            return ((entity_t *)(entity->data));
        }
        entity = entity->next;
    }
    return NULL;
}

int get_npc_index(char *name, linked_list_t *entity)
{
    int i = 0;

    while (entity != NULL) {
        if (((entity_t *)(entity->data))->type == NPC &&
            my_strcmp(((entity_t *)(entity->data))->npc->name, name) == 0) {
            return i;
            }
        entity = entity->next;
        i++;
    }
    return -1;
}

npc_t *get_index_npc(linked_list_t *entity, int i)
{
    while (i > 0) {
        if (entity == NULL)
            return NULL;
        entity = entity->next;
        i--;
    }
    if (entity == NULL)
        return NULL;
    if (((entity_t *)(entity->data)) == NULL ||
        ((entity_t *)(entity->data))->type != NPC)
        return NULL;
    return ((entity_t *)(entity->data))->npc;
}

entity_t *get_index_npc2(linked_list_t *entity, char *name)
{
    if (entity == NULL)
        return NULL;
    while (entity != NULL) {
        if (((entity_t *)(entity->data))->type == NPC &&
            my_strcmp(((entity_t *)(entity->data))->npc->name, name) == 0) {
            return (entity_t *)(entity->data);
            }
        entity = entity->next;
    }
    return NULL;
}
