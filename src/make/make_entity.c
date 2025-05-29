/*
** EPITECH PROJECT, 2024
** make_entity
** File description:
** make_entity
*/

#include "my.h"

static void make_scatter(sfRenderWindow *window, entity_t *entity, map_t *map)
{
    if (my_strcmp(entity->scatter->map, map->map->current_map) == 0)
        make_img(entity->scatter->scatter, window);
}

static void make_civ(sfRenderWindow *window, entity_t *entity)
{
    linked_list_t *clothes = entity->civ->clothes;

    make_img(entity->civ->civ, window);
    while (clothes) {
        make_img(clothes->data, window);
        clothes = clothes->next;
    }
}

void make_1_entity(sfRenderWindow *window, entity_t *entity, map_t *map)
{
    if (my_strcmp(map->map->current_map, "Night_City/") == 0 &&
        entity->type == CIVILIAN && no_collision_civils(map,
        sfSprite_getPosition(entity->civ->civ->sprite), entity))
        make_civ(window, entity);
    if (entity->type == SCATTER && my_strcmp(entity->scatter->map,
        map->map->current_map) == 0)
        make_scatter(window, entity, map);
    if (entity->type == NPC && my_strcmp(map->map->current_map,
        entity->npc->map) == 0)
        make_npc(window, entity->npc);
    if (entity->type == PC)
        make_player(window, entity->pc);
    if (entity->type == ITEM) {
        make_img(entity->item->icon, window);
    }
}

void make_entity(sfRenderWindow *window, linked_list_t **ll, map_t *map)
{
    linked_list_t *element = *ll;

    while (element != NULL) {
        if (((entity_t *)(element->data)) &&
            ((entity_t *)(element->data))->hidden == false)
            make_1_entity(window, (entity_t *)(element->data), map);
        element = element->next;
    }
}
