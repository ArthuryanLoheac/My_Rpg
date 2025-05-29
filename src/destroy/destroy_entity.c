/*
** EPITECH PROJECT, 2024
** destroy_entity
** File description:
** destroy_entity
*/

#include "my.h"

void destroy_1_entity(entity_t *entity)
{
    if (entity->type == CIVILIAN)
        destroy_civilian(entity->civ);
    if (entity->type == SCATTER) {
        free(entity->scatter->map);
        destroy_image(entity->scatter->scatter);
    }
    if (entity->type == NPC)
        destroy_npc(entity->npc);
    if (entity->type == PC)
        destroy_player(entity->pc);
    if (entity->type == ITEM)
        destroy_item(entity->item);
    free(entity);
}

void destroy_entity(linked_list_t *ll)
{
    linked_list_t *temp;

    while (ll != NULL) {
        destroy_1_entity((entity_t *)(ll->data));
        temp = ll;
        ll = ll->next;
        free(temp);
    }
}
