/*
** EPITECH PROJECT, 2024
** analyze_map
** File description:
** analyze_map
*/

#include "my.h"

static void analyze_buttons_level(level_up_menu_t *menu, game_t *game)
{
    analyze_gui_obj(game->window, game->events, menu->Move);
    analyze_gui_obj(game->window, game->events, menu->Tech);
    analyze_gui_obj(game->window, game->events, menu->Will);
    analyze_gui_obj(game->window, game->events, menu->Body);
    analyze_gui_obj(game->window, game->events, menu->REF);
    analyze_gui_obj(game->window, game->events, menu->Dexterity);
    analyze_gui_obj(game->window, game->events, menu->EMP);
    analyze_gui_obj(game->window, game->events, menu->LUCK);
}

static void analyze_buttons_escape(escape_menu_t *menu, game_t *game)
{
    analyze_gui_obj(game->window, game->events, menu->save->gui_obj);
    analyze_gui_obj(game->window, game->events, menu->load->gui_obj);
    analyze_gui_obj(game->window, game->events, menu->main_menu->gui_obj);
    analyze_gui_obj(game->window, game->events, menu->options);
    analyze_gui_obj(game->window, game->events, menu->quit);
}

void analyze_map(ui_obj_t *obj, game_t *game)
{
    map_t *map = (map_t *)obj->ui_content;

    if (map->fight->is_fight == false)
        analyze_diag_pipe(game, map->dialogue_pipeline);
    if (game->espace_active)
        analyze_buttons_escape(map->escape_menu, game);
    else if (game->level_up_active)
        analyze_buttons_level(map->level_menu, game);
    else
        analyze_inventory(obj, game);
    analyze_fight(obj, game);
}
