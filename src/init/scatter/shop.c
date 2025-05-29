/*
** EPITECH PROJECT, 2024
** init shopp
** File description:
** shop
*/

#include "my.h"

static void move_to_shop(game_t *game, map_t *map)
{
    (void) map;
    game->guis->active = SHOP_IN_GAME;
    sfView_setCenter(((map_t *)(game->guis->map->ui_content))->view,
        (sfVector2f){640, 315});
}

entity_t *init_chair_scatter(sfVector2f pos, assets_t **assets)
{
    entity_t *data = malloc(sizeof(entity_t));

    data->type = SCATTER;
    data->scatter = malloc(sizeof(scatter_t));
    data->scatter->scatter = init_image(get_asset("armchair", assets), pos, 1);
    data->scatter->id = 85;
    data->scatter->map = my_strdup("Night_City/");
    data->scatter->init_new = NULL;
    data->scatter->interact = true;
    return data;
}

entity_t *init_shop_scatter(sfVector2f pos, assets_t **assets, map_t *map)
{
    entity_t *data = malloc(sizeof(entity_t));

    data->type = SCATTER;
    data->scatter = malloc(sizeof(scatter_t));
    data->scatter->scatter = init_image(get_asset("SHOP", assets), pos, 1);
    data->scatter->id = 7;
    data->scatter->map = my_strdup("Night_City/");
    data->scatter->init_new = &move_to_shop;
    data->scatter->interact = true;
    draw_rectangle(map, pos, (sfVector2f){10, 86}, (sfVector2f){100, 134});
    return data;
}
