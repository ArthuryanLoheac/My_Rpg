/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** init_props_str
*/

#include "my.h"

entity_t *init_props_str(sfVector2f pos, assets_t **assets,
    char *str_f, int nb)
{
    entity_t *data = malloc(sizeof(entity_t));
    char str[20];
    int random = (rand() % nb) + 1;

    sprintf(str, str_f, random);
    data->type = SCATTER;
    data->scatter = malloc(sizeof(scatter_t));
    data->scatter->scatter = init_image(
        get_asset(str, assets), pos, 1);
    data->scatter->map = my_strdup("Night_City/");
    data->scatter->init_new = NULL;
    data->scatter->interact = false;
    return data;
}
