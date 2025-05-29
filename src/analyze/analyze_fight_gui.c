/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to analyze a message
*/

#include "my.h"

static void analyze_current_weapon_autofire(sfRenderWindow *window,
    fight_gui_t *gui, game_t *game, enum weapon_type_e type)
{
    analyze_gui_obj(window, game->events, gui->fire);
    if ((type == SMG || type == RIFLE))
        analyze_gui_obj(window, game->events, gui->autofire);
}

static void analyze_current_weapon(sfRenderWindow *window, fight_gui_t *gui,
    game_t *game)
{
    enum weapon_type_e type;

    if (((map_t *)(game->guis->map->ui_content))->inventory->inventory
        ->main_slots[12]->items == NULL) {
        analyze_gui_obj(window, game->events, gui->unarmd);
        return;
    }
    type = ((map_t *)(game->guis->map->ui_content))->inventory
        ->inventory->main_slots[12]->items->weapon->type;
    if (type < 7)
        analyze_current_weapon_autofire(window, gui, game, type);
    if (type == NADL || type == ROCKET_L)
        analyze_gui_obj(window, game->events, gui->expl);
    if (type == BOW)
        analyze_gui_obj(window, game->events, gui->bow);
    if (type == SHOTGUN)
        analyze_gui_obj(window, game->events, gui->shell);
    if (type >= 10 && type <= 13)
        analyze_gui_obj(window, game->events, gui->melee);
}

void analyze_fight_gui(sfRenderWindow *window, fight_gui_t *gui, game_t *game)
{
    analyze_gui_obj(window, game->events, gui->dash);
    analyze_gui_obj(window, game->events, gui->dodge);
    analyze_gui_obj(window, game->events, gui->done);
    analyze_current_weapon(window, gui, game);
}
