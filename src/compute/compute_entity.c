/*
** EPITECH PROJECT, 2024
** compute_entity
** File description:
** compute_entity
*/

#include "my.h"


static void compute_1_item(game_t *game, entity_t *entity)
{
    if (entity->item->id / 100 == 3)
        sfSprite_setScale(entity->item->icon->sprite, (sfVector2f){
            0.50, 0.50});
    else
        sfSprite_setScale(entity->item->icon->sprite, (sfVector2f){
            0.10, 0.10});
    (void) game;
}

void compute_1_entity(game_t *game, entity_t *entity)
{
    if (entity->type == NPC)
        compute_npc(game, entity);
    if (entity->type == SCATTER)
        compute_scatter(game, entity);
    if (entity->type == ITEM)
        compute_1_item(game, entity);
}

void compute_entity(game_t *game, linked_list_t **ll)
{
    linked_list_t *element = *ll;

    while (element != NULL) {
        if (((entity_t *)(element->data)) &&
            ((entity_t *)(element->data))->hidden == false)
            compute_1_entity(game, (entity_t *)(element->data));
        element = element->next;
    }
}
