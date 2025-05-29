/*
** EPITECH PROJECT, 2024
** analyze_guis
** File description:
** analyze_guis
*/

#include "my.h"

void analyze_guis(guis_t *guis, game_t *game)
{
    if (guis->active == CHOOSE_STATS && guis->choose_stats->analyze != NULL)
        guis->choose_stats->analyze(guis->choose_stats, game);
    if (guis->active == PAGE_SHOP && guis->shop->analyze != NULL)
        guis->shop->analyze(guis->shop, game);
    if (guis->active == PAGE_FINAL && guis->final->analyze != NULL)
        guis->final->analyze(guis->final, game);
    if (guis->active == MAIN_MENU && guis->main_menu->analyze != NULL)
        guis->main_menu->analyze(guis->main_menu, game);
    if (guis->active == OPTIONS && guis->options_page->analyze != NULL)
        guis->options_page->analyze(guis->options_page, game);
    if (guis->active == CHOOSE_CLASS && guis->choose_class->analyze != NULL)
        guis->choose_class->analyze(guis->choose_class, game);
    if (guis->active == SHOP_IN_GAME && guis->shop_in_game->analyze != NULL)
        guis->shop_in_game->analyze(guis->shop_in_game, game);
    if (guis->active == START_MENU && guis->start_menu->analyze != NULL)
        guis->start_menu->analyze(guis->start_menu, game);
    if (guis->active == MAP && guis->map->analyze != NULL)
        guis->map->analyze(guis->map, game);
}
