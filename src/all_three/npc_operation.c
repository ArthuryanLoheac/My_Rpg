/*
** EPITECH PROJECT, 2024
** init_map
** File description:
** init_map
*/

#include "my.h"

void set_npc_item_hidden(linked_list_t *ll)
{
    while (ll != NULL) {
        if (((entity_t *)(ll->data))->type == ITEM)
            ((entity_t *)(ll->data))->hidden = true;
        ll = ll->next;
    }
}

void set_npc_shown(linked_list_t *ll, char *name, bool val)
{
    while (ll != NULL) {
        if (((entity_t *)(ll->data))->type == NPC &&
            my_strcmp(((entity_t *)(ll->data))->npc->name, name) == 0)
            ((entity_t *)(ll->data))->hidden = val;
        ll = ll->next;
    }
}

void set_npc_pos(linked_list_t *ll, char *name, sfVector2f pos)
{
    while (ll != NULL) {
        if (((entity_t *)(ll->data))->type == NPC &&
            my_strcmp(((entity_t *)(ll->data))->npc->name, name) == 0)
            sfSprite_setPosition(((entity_t *)(ll->data))->npc->npc->sprite,
                pos);
        ll = ll->next;
    }
}
