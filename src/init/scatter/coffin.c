/*
** EPITECH PROJECT, 2024
** init_coffin()
** File description:
** init_coffin()
*/
#include "my.h"

void coffin_action(game_t *game, map_t *map)
{
    game->quests->prog.x++;
    get_scatter(6, map->entity_all)->scatter->init_new = NULL;
    map->dialogue = append_to_array2(game->quests->prefix,
        my_str_to_word_array("protagonist/speech", ";", 0));
}

entity_t *init_coffin(sfVector2f pos, assets_t **assets, map_t *map)
{
    entity_t *coffin = malloc(sizeof(entity_t));

    coffin->hidden = false;
    coffin->type = SCATTER;
    coffin->scatter = init_coffin_scatter(pos, assets);
    coffin->position = pos;
    coffin->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    coffin->move = false;
    draw_rectangle(map, pos, (sfVector2f){0, 64}, (sfVector2f){16, 120});
    return coffin;
}

scatter_t *init_coffin_scatter(sfVector2f pos, assets_t **assets)
{
    scatter_t *coffin = malloc(sizeof(scatter_t));

    coffin->scatter = init_image(get_asset("coffin", assets), pos, 1);
    coffin->init_new = NULL;
    coffin->interact = true;
    coffin->id = 6;
    coffin->map = my_strdup("Night_City/");
    return coffin;
}
