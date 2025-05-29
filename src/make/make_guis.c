/*
** EPITECH PROJECT, 2024
** make_guis
** File description:
** make_guis
*/

#include "my.h"

void make_guis(guis_t *guis, game_t *game)
{
    if (guis->active == MAIN_MENU && guis->main_menu->make != NULL)
        guis->main_menu->make(guis->main_menu, game);
    if (guis->active == PAGE_FINAL && guis->final->make != NULL)
        guis->final->make(guis->final, game);
    if (guis->active == PAGE_SHOP && guis->shop->make != NULL)
        guis->shop->make(guis->shop, game);
    if (guis->active == CHOOSE_STATS && guis->choose_stats->make != NULL)
        guis->choose_stats->make(guis->choose_stats, game);
    if (guis->active == SHOP_IN_GAME && guis->shop_in_game->make != NULL)
        guis->shop_in_game->make(guis->shop_in_game, game);
    if (guis->active == CHOOSE_CLASS && guis->choose_class->make != NULL)
        guis->choose_class->make(guis->choose_class, game);
    if (guis->active == OPTIONS && guis->options_page->make != NULL)
        guis->options_page->make(guis->options_page, game);
    if (guis->active == START_MENU && guis->start_menu->make != NULL)
        guis->start_menu->make(guis->start_menu, game);
    if (guis->active == MAP && guis->map->make != NULL)
        guis->map->make(guis->map, game);
}
