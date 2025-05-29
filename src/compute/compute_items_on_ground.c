/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-matthieu.guillet-arnaud
** File description:
** TODO: add description
*/

#include "my.h"

static void empty_ll(linked_list_t **entity)
{
    linked_list_t *element = *entity;
    linked_list_t *temp = NULL;

    if (!entity)
        return;
    while (element) {
        temp = element->next;
        free(element);
        element = temp;
    }
    *entity = NULL;
}

static void add_element_to_area(linked_list_t **area_list, linked_list_t
    *data_add)
{
    linked_list_t *element = malloc(sizeof(linked_list_t));

    element->next = *area_list;
    element->prev = NULL;
    if (*area_list)
        (*area_list)->prev = element;
    element->data = data_add->data;
    *area_list = element;
}

static void complete_area_list(linked_list_t **area_list, linked_list_t
    **dropped_list, sfView *view)
{
    linked_list_t *element = *dropped_list;
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);
    sfFloatRect viewRect = {center.x - size.x / 2, center.y - size.y / 2,
        size.x, size.y};
    sfFloatRect viewRect_sprite;
    sfSprite *data_sprite = NULL;

    while (element) {
        data_sprite = get_sprite(((entity_t *)(element->data)));
        viewRect_sprite = sfSprite_getGlobalBounds(data_sprite);
        if (sfFloatRect_intersects(&viewRect, &viewRect_sprite, NULL) ==
            sfTrue)
            add_element_to_area(area_list, element);
        element = element->next;
    }
}

static void remove_node(linked_list_t **element)
{
    linked_list_t *next = (*element)->next;
    linked_list_t *prev = (*element)->prev;

    if (prev)
        prev->next = next;
    if (next)
        next->prev = prev;
    free(*element);
    *element = NULL;
}

static int remove_node_item_dropped_area(linked_list_t *element_data,
    linked_list_t **area_list)
{
    linked_list_t *element = element_data;
    int id_node = ((entity_t *)(element->data))->id_item;

    if (id_node == ((entity_t *)((element)->data))->id_item) {
        if (element == *area_list) {
            *area_list = element->next;
            return id_node;
        }
    }
    while (element) {
        if (id_node == ((entity_t *)((element)->data))->id_item) {
            remove_node(&element);
            return id_node;
        }
        element = element->next;
    }
    return id_node;
}

static void remove_node_item_dropped_glb_list(linked_list_t **glb_list,
    int id_node)
{
    linked_list_t *element = *glb_list;

    if (id_node == ((entity_t *)((element)->data))->id_item) {
        if (*glb_list == element) {
            *glb_list = element->next;
            return;
        }
    }
    while (element) {
        if (id_node == ((entity_t *)((element)->data))->id_item) {
            remove_node(&element);
            return;
        }
        element = element->next;
    }
}

static void reset_scale(item_t *item)
{
    if (item->id / 100 == 3)
        sfSprite_setScale(item->icon->sprite, (sfVector2f){0.81,
            0.81});
    else
        sfSprite_setScale(item->icon->sprite, (sfVector2f){0.20,
            0.20});
}

static int check_add_inventory(inventory_slots_t *inv, item_t *item,
    linked_list_t *element, linked_list_t **entity)
{
    main_slots_t **slots = inv->main_slots;

    for (int i = 0; i < 20; i++) {
        if (slots[i] && slots[i]->items == NULL && slots[i]->slot_type ==
        INVENTORY_SLOTS) {
            slots[i]->items = item;
            reset_scale(item);
            sfSprite_setPosition(item->icon->sprite, slots[i]->position_icon);
            ((entity_t *)(element->data))->item = NULL;
            return remove_node_item_dropped_area(element, entity);
        }
    }
    return -1;
}

static void check_collision_player(linked_list_t **entity, img_t *player,
    inventory_slots_t *inv, linked_list_t **dropped_items)
{
    linked_list_t *element = *entity;
    sfFloatRect viewRect_sprite = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect viewRect_item;
    item_t *items_data = NULL;
    int id = -1;

    while (element) {
        if (((entity_t *)(element->data))->type == ITEM) {
            items_data = ((entity_t *) (element->data))->item;
            viewRect_item = sfSprite_getGlobalBounds(items_data->icon->sprite);
        }
        if (items_data && sfFloatRect_intersects(&viewRect_item,
            &viewRect_sprite, NULL) == sfTrue) {
            id = check_add_inventory(inv, items_data, element, entity);
            break;
        }
        element = element->next;
    }
    if (id != -1)
        remove_node_item_dropped_glb_list(dropped_items, id);
}

void compute_items_on_ground(game_t *game)
{
    map_t *data_map = game->guis->map->ui_content;

    empty_ll(&(data_map->entity_area));
    complete_area_list(&(data_map->entity_area), &(data_map->entity_all),
        data_map->view);
    if ((game->events->type == sfEvtKeyReleased) && (game->events->key.code ==
    game->keybinds->interact)) {
        check_collision_player(&(data_map->entity_area),
        game->player->sprite->temp, data_map->inventory->inventory, &(data_map
        ->entity_all));
    }
}
