/*
** EPITECH PROJECT, 2024
** analyze_buttons_start_menu
** File description:
** analyze_buttons_start_menu
*/

#include "my.h"
void analyze_menu_start(ui_obj_t *obj, game_t *game)
{
    start_t *menu = (start_t *)obj->ui_content;

    analyze_gui_obj(game->window, game->events, menu->continues);
    analyze_gui_obj(game->window, game->events, menu->nouveau);
    analyze_gui_obj(game->window, game->events, menu->retour);
}
