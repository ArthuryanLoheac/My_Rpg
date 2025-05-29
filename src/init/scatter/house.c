/*
** EPITECH PROJECT, 2024
** init_door()
** File description:
** init_door()
*/
#include "my.h"

entity_t *init_building_name(sfVector2f pos, assets_t **assets, char *str)
{
    entity_t *door = malloc(sizeof(entity_t));

    door->hidden = false;
    door->type = SCATTER;
    door->scatter = malloc(sizeof(scatter_t));
    door->scatter->id = 9;
    door->scatter->scatter = init_image(get_asset(
        str, assets), pos, SCALE_HOUSE);
    door->scatter->init_new = NULL;
    door->scatter->interact = false;
    door->position = pos;
    door->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    door->move = false;
    door->scatter->map = my_strdup("Night_City/");
    return door;
}

entity_t *init_building_shop(sfVector2f pos, assets_t **assets, char *str)
{
    entity_t *door = malloc(sizeof(entity_t));

    door->hidden = false;
    door->type = SCATTER;
    door->scatter = malloc(sizeof(scatter_t));
    door->scatter->id = 9;
    door->scatter->scatter = init_image(get_asset(
        str, assets), pos, 1);
    door->scatter->init_new = NULL;
    door->scatter->interact = false;
    door->position = pos;
    door->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    door->move = false;
    door->scatter->map = my_strdup("Night_City/");
    return door;
}
