/*
** EPITECH PROJECT, 2024
** init shopp
** File description:
** shop
*/

#include "my.h"

entity_t *init_trash(sfVector2f pos, assets_t **assets)
{
    entity_t *data = malloc(sizeof(entity_t));

    pos = (sfVector2f){pos.x - 48, pos.y - 72};
    data->type = SCATTER;
    data->scatter = malloc(sizeof(scatter_t));
    if (rand() % 2)
        data->scatter->scatter = init_image(
            get_asset("Trash_1", assets), pos, 1);
    else
        data->scatter->scatter = init_image(
            get_asset("Trash_2", assets), pos, 1);
    data->scatter->map = my_strdup("Night_City/");
    data->scatter->init_new = NULL;
    data->scatter->interact = false;
    return data;
}
