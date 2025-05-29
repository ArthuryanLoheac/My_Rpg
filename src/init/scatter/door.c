/*
** EPITECH PROJECT, 2024
** init_door()
** File description:
** init_door()
*/
#include "my.h"

entity_t *init_door(sfVector2f pos, assets_t **assets)
{
    entity_t *door = malloc(sizeof(entity_t));

    door->hidden = false;
    door->type = SCATTER;
    door->scatter = init_door_scatter(pos, assets);
    door->position = pos;
    door->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    door->move = false;
    return door;
}

scatter_t *init_door_scatter(sfVector2f pos, assets_t **assets)
{
    scatter_t *door = malloc(sizeof(scatter_t));

    door->scatter = init_image(get_asset("door1", assets), pos, 2.28);
    door->init_new = &load_house1;
    door->interact = false;
    door->id = 1;
    door->map = my_strdup("Night_City/");
    return door;
}

static void out_of_queen_house(game_t *game, map_t *map)
{
    load_nc(game, map);
    sfSprite_setPosition(map->player->sprite->temp->sprite, (sfVector2f){1600,
        3700});
    sfView_setCenter(map->view, (sfVector2f){1600, 3700});
}

entity_t *init_door2(sfVector2f pos, assets_t **assets)
{
    entity_t *door = malloc(sizeof(entity_t));

    door->hidden = false;
    door->type = SCATTER;
    door->scatter = init_door_scatter2(pos, assets);
    door->position = pos;
    door->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    door->move = false;
    return door;
}

scatter_t *init_door_scatter2(sfVector2f pos, assets_t **assets)
{
    scatter_t *door = malloc(sizeof(scatter_t));

    door->scatter = init_image(get_asset("door1", assets), pos, 2.28);
    sfSprite_setColor(door->scatter->sprite, sfTransparent);
    door->init_new = &out_of_queen_house;
    door->interact = false;
    door->id = 3;
    door->map = my_strdup("QueenHouse/");
    return door;
}
