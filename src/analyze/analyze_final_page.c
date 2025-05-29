/*
** EPITECH PROJECT, 2024
** analyze_final_page
** File description:
** analyze_final_page
*/

#include "my.h"

void analyze_final_page(ui_obj_t *obj, game_t *game)
{
    page_final_t *options = (page_final_t *)obj->ui_content;

    analyze_gui_obj(game->window, game->events, options->valider);
    analyze_gui_obj(game->window, game->events, options->female->gui_obj);
    analyze_gui_obj(game->window, game->events, options->male->gui_obj);
}
