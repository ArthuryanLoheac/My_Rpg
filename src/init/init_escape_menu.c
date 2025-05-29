/*
** EPITECH PROJECT, 2024
** init_map
** File description:
** init_map
*/

#include "my.h"

escape_menu_t *init_escape_menu(game_t *game)
{
    escape_menu_t *menu = malloc(sizeof(escape_menu_t));

    menu->quit = init_gui_obj_img("Boutton_Quitter", (sfVector2f){820, 800},
        (sfVector2f){280, 80}, game);
    menu->options = init_gui_obj_img("Boutton_Options", vect0(),
        (sfVector2f){280, 80}, game);
    menu->main_menu = init_button((sfVector2f){820, 800},
        (sfVector2f){280, 80}, "Menu", game->assets);
    menu->save = init_button((sfVector2f){820, 600},
        (sfVector2f){280, 80}, "SAVE", game->assets);
    menu->load = init_button((sfVector2f){820, 600},
        (sfVector2f){280, 80}, "LOAD", game->assets);
    return menu;
}
