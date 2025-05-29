/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** update_position_entity
*/
#include "my.h"

static void check_scatter(entity_t *entity_data)
{
    if (entity_data->type == SCATTER)
        entity_data->position = sfSprite_getPosition(
        entity_data->scatter->scatter->sprite);
}

void update_position_entity(linked_list_t **entity)
{
    linked_list_t *element = *entity;
    entity_t *entity_data = NULL;

    while (element) {
        entity_data = ((entity_t *)(element->data));
        if (entity_data->type == CIVILIAN)
            sfSprite_setPosition(entity_data->civ->civ->sprite,
                entity_data->position);
        if (entity_data->type == ITEM)
            entity_data->position = sfSprite_getPosition
                (entity_data->item->icon->sprite);
        if (entity_data->type == PC)
            entity_data->position = sfSprite_getPosition(entity_data->pc->
                sprite->temp->sprite);
        check_scatter(entity_data);
        element = element->next;
    }
}
