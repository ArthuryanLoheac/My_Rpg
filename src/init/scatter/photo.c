/*
** EPITECH PROJECT, 2024
** init_photo()
** File description:
** init_photo()
*/
#include "my.h"

void quest_increase3(game_t *game, map_t *map)
{
    game->quests->prog.x += 4;
    get_scatter(5, map->entity_all)->hidden = true;
    get_scatter(5, map->entity_all)->scatter->init_new = NULL;
    map->dialogue = diag(game->quests->prefix, "memories/photo");
    (void) map;
}

entity_t *init_photo(sfVector2f pos, assets_t **assets)
{
    entity_t *photo = malloc(sizeof(entity_t));

    photo->hidden = true;
    photo->type = SCATTER;
    photo->scatter = init_photo_scatter(pos, assets);
    photo->position = pos;
    photo->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    photo->move = false;
    return photo;
}

scatter_t *init_photo_scatter(sfVector2f pos, assets_t **assets)
{
    scatter_t *photo = malloc(sizeof(scatter_t));

    photo->scatter = init_image(get_asset("photo", assets), pos, 1.28);
    photo->init_new = &quest_increase3;
    photo->interact = true;
    photo->id = 5;
    photo->map = my_strdup("QueenHouse/");
    return photo;
}
