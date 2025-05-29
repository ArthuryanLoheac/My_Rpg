/*
** EPITECH PROJECT, 2024
** init_sat_down()
** File description:
** init_sat_down()
*/
#include "my.h"

entity_t *init_sat_down(sfVector2f pos, assets_t **assets, int gender)
{
    entity_t *sat_down = malloc(sizeof(entity_t));

    sat_down->hidden = false;
    sat_down->type = SCATTER;
    sat_down->scatter = init_sat_down_scatter(pos, assets, gender);
    sat_down->position = pos;
    sat_down->map = (int)pos.x / 1920 + (int)pos.y / 1080 * 9;
    sat_down->move = false;
    return sat_down;
}

scatter_t *init_sat_down_scatter(sfVector2f pos, assets_t **assets, int gender)
{
    scatter_t *sat_down = malloc(sizeof(scatter_t));

    if (gender == 1) {
        sat_down->scatter = init_image(get_asset("sat_downb", assets), pos, 1);
        sfSprite_setOrigin(sat_down->scatter->sprite, (sfVector2f){50, 48});
    } else if (gender == 2) {
        sat_down->scatter = init_image(get_asset("sat_downg", assets), pos, 1);
        sfSprite_setOrigin(sat_down->scatter->sprite, (sfVector2f){50, 48});
    } else {
        sat_down->scatter = init_image(get_asset("sat_down", assets), pos, 1);
        sfSprite_setOrigin(sat_down->scatter->sprite, (sfVector2f){64, 64});
    }
    sat_down->init_new = NULL;
    sat_down->interact = true;
    sat_down->id = 8;
    sat_down->map = my_strdup("Briefing/");
    return sat_down;
}
