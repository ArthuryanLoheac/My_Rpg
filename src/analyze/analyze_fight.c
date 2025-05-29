/*
** EPITECH PROJECT, 2024
** analyze_menu_start
** File description:
** analyze_menu_start
*/

#include "my.h"

void analyze_fight(ui_obj_t *obj, game_t *game)
{
    map_t *map = (map_t *)obj->ui_content;

    if (get_pc_index(map->fight->turn_order) == map->fight->fighter)
        analyze_fight_gui(game->window, map->fight->gui, game);
}
