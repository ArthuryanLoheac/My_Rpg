/*
** EPITECH PROJECT, 2024
** compute_npc
** File description:
** compute_npc
*/

#include "my.h"

void destroy_current_queued_nextpos(npc_t *npc)
{
    linked_list_t *temp;

    free(npc->next_pos->data);
    temp = npc->next_pos;
    npc->next_pos = npc->next_pos->next;
    free(temp);
}

static void compute_npc_pos(game_t *game, entity_t *entity)
{
    linked_list_t *lst = entity->npc->clothes;

    entity->position = sfSprite_getPosition(entity->npc->npc->sprite);
    while (lst) {
        sfSprite_setPosition(((img_t *)(lst->data))->sprite, entity->position);
        ((img_t *)(lst->data))->animate->rect.top =
            entity->npc->npc->animate->rect.top;
        ((img_t *)(lst->data))->animate->rect.left =
            entity->npc->npc->animate->rect.left;
        lst = lst->next;
    }
    (void) game;
}

static void compute_npc_animation(float delta,
    entity_t *entity, npc_t *npc)
{
    sfVector2f *next_pos = npc->next_pos->data;

    if (get_distance(*next_pos, entity->position) < 5) {
        sfSprite_setPosition(entity->npc->npc->sprite, *next_pos);
        destroy_current_queued_nextpos(npc);
        return;
    }
    if (next_pos->x < 0 && next_pos->y > 0) {
        next_pos->y = next_pos->y - delta;
    } else if (next_pos->x < 0) {
        destroy_current_queued_nextpos(npc);
        return;
    } else {
        sfSprite_move(npc->npc->sprite, mult3(normalize(sub2(
            *next_pos, entity->position)), 200 * delta));
    }
}

void compute_npc(game_t *game, entity_t *entity)
{
    npc_t *npc = entity->npc;
    float delta = 0;
    linked_list_t *lst = entity->npc->clothes;

    update_time(npc->own_clock);
    delta = npc->own_clock->seconds;
    compute_talk(game, entity->npc);
    if (npc->hp.x > 0)
        compute_animation_img(entity->npc->npc->animate, false);
    if (npc->next_pos != NULL)
        compute_npc_animation(delta, entity, npc);
    sfClock_restart(npc->own_clock->clock);
    while (lst) {
        if (npc->hp.x > 0)
            compute_animation_img(((img_t *)(lst->data))->animate, false);
        lst = lst->next;
    }
    compute_npc_pos(game, entity);
}
