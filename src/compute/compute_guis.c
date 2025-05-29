/*
** EPITECH PROJECT, 2024
** compute_guis
** File description:
** compute_guis
*/

#include "my.h"

void compute_guis(guis_t *guis, game_t *game)
{
    if (guis->active == PAGE_FINAL && guis->final->compute != NULL)
        guis->final->compute(guis->final, game);
    if (guis->active == START_MENU && guis->start_menu->compute != NULL)
        guis->start_menu->compute(guis->start_menu, game);
    if (guis->active == PAGE_SHOP && guis->shop->compute != NULL)
        guis->shop->compute(guis->shop, game);
    if (guis->active == OPTIONS && guis->options_page->compute != NULL)
        guis->options_page->compute(guis->options_page, game);
    if (guis->active == CHOOSE_CLASS && guis->choose_class->compute != NULL)
        guis->choose_class->compute(guis->choose_class, game);
    if (guis->active == CHOOSE_STATS && guis->choose_stats->compute != NULL)
        guis->choose_stats->compute(guis->choose_stats, game);
    if (guis->active == SHOP_IN_GAME && guis->shop_in_game->compute != NULL)
        guis->shop_in_game->compute(guis->shop_in_game, game);
    if (guis->active == MAIN_MENU && guis->main_menu->compute != NULL)
        guis->main_menu->compute(guis->main_menu, game);
    if (guis->active == MAP && guis->map->compute != NULL)
        guis->map->compute(guis->map, game);
}
