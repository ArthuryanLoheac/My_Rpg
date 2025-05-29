/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-matthieu.guillet-arnaud
** File description:
** TODO: add description
*/

#include "my.h"

sfSprite *get_sprite(entity_t *entity)
{
    if (entity->type == PC)
        return entity->pc->sprite->temp->sprite;
    if (entity->type == ITEM)
        return entity->item->icon->sprite;
    if (entity->type == NPC)
        return entity->npc->npc->sprite;
    if (entity->type == CIVILIAN)
        return entity->civ->civ->sprite;
    if (entity->type == SCATTER)
        return entity->scatter->scatter->sprite;
    return NULL;
}
