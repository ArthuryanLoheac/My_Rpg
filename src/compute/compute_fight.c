/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

static void compute_equiped_weapon(map_t *map)
{
    weapon_t *weapon;

    if (map->inventory->inventory->main_slots[12]->items == NULL) {
        map->fight->gui->mode = false;
        return;
    }
    weapon = map->inventory->inventory->main_slots[12]->items
        ->weapon;
    if (weapon->type != SMG && weapon->type != RIFLE)
        map->fight->gui->mode = false;
}

void compute_fight(ui_obj_t *obj, game_t *game)
{
    map_t *map = (map_t *)obj->ui_content;
    fight_t *f = map->fight;
    static int prev_fighter = 0;

    compute_equiped_weapon(map);
    if (f->fighter >= my_list_size(f->turn_order))
        f->fighter = 0;
    if (get_pc_index(f->turn_order) == f->fighter) {
        prev_fighter = f->fighter;
        compute_player_turn(game, obj, map);
    } else {
        if (get_index_npc(f->turn_order, f->fighter)->hp.x <= 0)
            return npc_death(game, map);
        if (compute_npc_fight(map, game, get_index_npc(f->turn_order,
            f->fighter), prev_fighter != f->fighter) == true)
            f->fighter++;
        else
            prev_fighter = f->fighter;
    }
    compute_fight_gui_pos(game->window, f->gui);
}
