/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"


char *get_particule_grp(char *data)
{
    char *result = NULL;
    int nbr = 0;

    for (; data[nbr] != 'M'; nbr++);
    result = malloc(sizeof(char) * (nbr + 1));
    result[nbr] = '\0';
    for (int i = 0; data[i] != 'M'; i++)
        result[i] = data[i];
    return result;
}

static int check_range_npc(linked_list_t *ll, sfFloatRect *player,
    map_t *map, game_t *game)
{
    sfFloatRect npc = {0, 0, 0, 0};

    if (((entity_t *)(ll->data))->type == NPC && ((entity_t *)(ll->data))->
        npc->type == HOSTILE && my_strcmpstart(((entity_t *)(ll->data))->
        npc->name, "!") == 0 && ((entity_t *)(ll->data))->npc->hp.x > 0) {
        npc = sfSprite_getGlobalBounds(((entity_t *)(ll->data))->
            npc->npc->sprite);
        if (sfFloatRect_intersects(player, &npc, NULL)) {
            start_fight_groups(game, map, get_particule_grp(((entity_t *)
                (ll->data))->npc->name));
            return 1;
        }
    }
    return 0;
}

static void check_hostile_area_mook(map_t *map, game_t *game)
{
    linked_list_t *ll = map->entity_area;
    sfFloatRect player = {0, 0, 0, 0};

    if (map->fight->is_fight)
        return;
    sfRectangleShape_setPosition(map->player->range_trigger,
        add2(sfSprite_getPosition(map->player->sprite->temp->sprite),
        (sfVector2f){-250, -250}));
    while (ll) {
        player = sfRectangleShape_getGlobalBounds(map->player->range_trigger);
        if (check_range_npc(ll, &player, map, game) == 1)
            return;
        ll = ll->next;
    }
}

void compute_view_pos(game_t *game, map_t *map)
{
    sfVector2f res;
    float sec = 0;

    update_time(map->view_clock);
    sec = map->view_clock->seconds;
    if (sfView_getCenter(map->view).x != map->target_view.x ||
        sfView_getCenter(map->view).y != map->target_view.y) {
        res = mult3(sub2(map->target_view, sfView_getCenter(map->view)),
            fmin(sec * 2, 0.025));
        sfView_setCenter(map->view, add2(sfView_getCenter(map->view), res));
    }
    sfRenderWindow_setView(game->window, map->view);
    sfClock_restart(map->view_clock->clock);
    check_hostile_area_mook(map, game);
    compute_weather(map);
}
