/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-matthieu.guillet-arnaud
** File description:
** compute_check_is_view
*/

#include "my.h"

static void set_previous_node(linked_list_t *element, linked_list_t *temp)
{
    if (element->next)
        element->next->prev = temp;
}

linked_list_t *check_is_view(bool *is_player, linked_list_t *element,
    const int *data_node, sfView *view)
{
    sfSprite *data;
    sfFloatRect data_rect;
    linked_list_t *temp = NULL;
    sfVector2f c = sfView_getCenter(view);
    sfVector2f s = sfView_getSize(view);
    sfFloatRect viewRect = {c.x - (s.x / 2), c.y - (s.y / 2), s.x, s.y};

    if (data_node[0] == data_node[1]) {
        data = ((entity_t *)(element->data))->pc->sprite->temp->sprite;
        data_rect = sfSprite_getGlobalBounds(data);
        if (sfFloatRect_intersects(&viewRect, &data_rect, NULL) ==
            sfTrue) {
            *is_player = true;
            temp = element->prev;
            temp->next = element->next;
            set_previous_node(element, temp);
            return element;
        }
    }
    return NULL;
}
