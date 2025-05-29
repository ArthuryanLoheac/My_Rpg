/*
** EPITECH PROJECT, 2024
** compute_guis
** File description:
** compute_guis
*/

#include "my.h"

int count_hostile(linked_list_t *ll)
{
    int count = 0;

    while (ll != NULL) {
        if (((entity_t *)(ll->data))->hidden == false && ((entity_t *)
            (ll->data))->type == NPC && ((entity_t *)(ll->data))
            ->npc->type == HOSTILE)
            count++;
        ll = ll->next;
    }
    return count;
}

static void stop_attack_music(game_t *game)
{
    sfMusic_stop(game->music->combat_music);
    sfMusic_destroy(game->music->combat_music);
    sfMusic_play(game->music->main_theme);
    game->music->combat_music = NULL;
}

void end_fight(game_t *game, map_t *map)
{
    linked_list_t *ll = map->fight->turn_order;
    linked_list_t *temp;

    stop_attack_music(game);
    while (ll != NULL) {
        temp = ll;
        ll = ll->next;
        free(temp);
    }
    map->fight->is_fight = false;
    map->fight->turn_order = NULL;
    map->player->movmult = 1;
    map->player->euro_dollars += rand() % MONEY_EARN + 20;
    map->fight->dep_mouv.x = map->fight->dep_mouv.y;
    (void) game;
}
