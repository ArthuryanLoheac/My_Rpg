/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-matthieu.guillet-arnaud
** File description:
** TODO: add description
*/

#include "my.h"

void drop_item(linked_list_t **pos, game_t **game, sfVector2f
    position, int id)
{
    linked_list_t *element = malloc(sizeof(linked_list_t));
    entity_t *data_added = malloc(sizeof(entity_t));

    data_added->item = init_item(id, (*game)->assets);
    data_added->type = ITEM;
    data_added->hidden = false;
    data_added->position = position;
    data_added->id_item = ((map_t *)((*game)->guis->map->ui_content))->
        id_dropped;
    ((map_t *)((*game)->guis->map->ui_content))->id_dropped = ((map_t *)
        ((*game)->guis->map->ui_content))->id_dropped + 1;
    sfSprite_setPosition(data_added->item->icon->sprite, position);
    element->data = data_added;
    element->next = *pos;
    element->prev = NULL;
    if (*pos)
        (*pos)->prev = element;
    *pos = element;
}

void drop_item_with_item(linked_list_t **pos, map_t **map, sfVector2f
    position, item_t *item)
{
    linked_list_t *element = malloc(sizeof(linked_list_t));
    entity_t *data_added = malloc(sizeof(entity_t));

    data_added->item = item;
    data_added->type = ITEM;
    data_added->hidden = false;
    data_added->position = position;
    data_added->id_item = (*map)->id_dropped;
    (*map)->id_dropped = (*map)->id_dropped + 1;
    sfSprite_setPosition(data_added->item->icon->sprite, position);
    element->data = data_added;
    element->next = *pos;
    element->prev = NULL;
    if (*pos)
        (*pos)->prev = element;
    *pos = element;
}
