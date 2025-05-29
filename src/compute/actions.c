/*
** EPITECH PROJECT, 2024
** actions
** File description:
** actions in combat
*/

#include "my.h"

void done(map_t *map)
{
    main_slots_t **main_slots_v = map->inventory->inventory->main_slots;

    map->fight->fighter++;
    map->fight->action_taken = false;
    map->fight->dep_mouv.x = map->fight->dep_mouv.y;
    if (main_slots_v[8]->items && main_slots_v[8]->items->id >= 104) {
        map->fight->dep_mouv.x -= 100;
    }
    if (main_slots_v[8]->items && main_slots_v[8]->items->id >= 106) {
        map->fight->dep_mouv.x -= 100;
    }
    compute_mana_bar(map->fight);
}

void dash(ui_obj_t *obj, game_t *game)
{
    map_t *map = (map_t *)obj->ui_content;

    map->fight->action = DASH;
    map->fight->dep_mouv.x += map->fight->dep_mouv.y;
    compute_mana_bar(map->fight);
    map->fight->action_taken = true;
    (void) game;
}

void dodge(ui_obj_t *obj, game_t *game)
{
    map_t *map = (map_t *)obj->ui_content;

    map->fight->action = DODGE;
    map->fight->action_taken = true;
    return;
    (void) game;
}

void fire(ui_obj_t *obj, game_t *game)
{
    map_t *map = (map_t *)obj->ui_content;

    if (player_second_action(game)) {
        map->fight->fired = false;
        map->fight->dep_mouv.x = 0;
    }
    compute_mana_bar(map->fight);
    map->fight->action = SHOOT;
    map->fight->action_taken = true;
    (void) game;
}
