/*
** EPITECH PROJECT, 2024
** quest
** File description:
** init_quest
*/

#include "my.h"

char **diag(char *prefix, char *diags)
{
    return append_to_array2(prefix, my_str_to_word_array(diags, ";", 0));
}

sfVector2f *vector(float x, float y)
{
    sfVector2f *vect = malloc(sizeof(sfVector2f));

    vect->x = x;
    vect->y = y;
    return vect;
}

bool empty_diag(map_t *map)
{
    if (map->dialogue_pipeline->text == NULL && map->dialogue_pipeline->ll ==
        NULL)
        return true;
    return false;
}

bool is_in_fight(char *name, linked_list_t *entity)
{
    linked_list_t *l = entity;

    while (l != NULL) {
        if (((entity_t *)(l->data))->hidden == false && ((entity_t *)(l->data))
            ->type == NPC && ((entity_t *)(l->data))->npc->type == HOSTILE &&
            my_strcmpstart(((entity_t *)(l->data))->npc->name, name) == 0 && (
            (((entity_t *)(l->data))->npc->hp.x != ((entity_t *)(l->data))
            ->npc->hp.y) || (((entity_t *)(l->data))->npc->ranged &&
            (((entity_t *)(l->data))->npc->ranged->weapon->magazine.x !=
            ((entity_t *)(l->data))->npc->ranged->weapon->magazine.y)))) {
            return true;
        }
        l = l->next;
    }
    return false;
}
