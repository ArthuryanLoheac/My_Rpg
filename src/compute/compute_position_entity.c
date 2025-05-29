/*
** EPITECH PROJECT, 2024
** sorting
** File description:
** compute_position_entity
*/

#include "my.h"

static sfFloatRect get_data_sprite(entity_t *data)
{
    if (data->type == PC)
        return sfSprite_getGlobalBounds(data->pc->sprite->temp->sprite);
    if (data->type == NPC)
        return sfSprite_getGlobalBounds(data->npc->npc->sprite);
    if (data->type == CIVILIAN)
        return sfSprite_getGlobalBounds(data->civ->civ->sprite);
    if (data->type == ITEM)
        return sfSprite_getGlobalBounds(data->item->icon->sprite);
    if (data->type == SCATTER)
        return sfSprite_getGlobalBounds(data->scatter->scatter->sprite);
    return (sfFloatRect){0, 0, 0, 0};
}

static void split_list(linked_list_t *pos, linked_list_t **first,
    linked_list_t **second)
{
    linked_list_t *next = pos->next;
    linked_list_t *prev = pos;

    while (next) {
        next = next->next;
        if (next) {
            prev = prev->next;
            next = next->next;
        }
    }
    *first = pos;
    *second = prev->next;
    prev->next = NULL;
}

static linked_list_t *sorted_merge(linked_list_t *a, linked_list_t *b)
{
    entity_t *a_data = a != NULL ? (entity_t *)a->data : NULL;
    entity_t *b_data = b != NULL ? (entity_t *)b->data : NULL;
    sfFloatRect data_sprite[2];

    if (!a)
        return b;
    if (!b)
        return a;
    data_sprite[0] = get_data_sprite(b_data);
    data_sprite[1] = get_data_sprite(a_data);
    return check_swapping_node(data_sprite, &a, &b);
}

linked_list_t *check_swapping_node(sfFloatRect data_sprite[2],
    linked_list_t **a, linked_list_t **b)
{
    linked_list_t *result = NULL;

    if ((data_sprite[0].top + data_sprite[0].height) >
        (data_sprite[1].top + data_sprite[1].height)) {
        result = *a;
        result->next = sorted_merge((*a)->next, *b);
        result->next->prev = result;
        result->prev = NULL;
    } else {
        result = *b;
        result->next = sorted_merge(*a, (*b)->next);
        result->next->prev = result;
        result->prev = NULL;
    }
    return result;
}

static void merge_sort(linked_list_t **entity)
{
    linked_list_t *pos = *entity;
    linked_list_t *first = NULL;
    linked_list_t *second = NULL;

    if ((!pos) || (!(pos->next)))
        return;
    split_list(pos, &first, &second);
    merge_sort(&first);
    merge_sort(&second);
    *entity = sorted_merge(first, second);
}

void sort_entity_list(linked_list_t **entity, sfView *view)
{
    (void) view;
    update_position_entity(entity);
    if ((*entity))
        merge_sort(entity);
}
