/*
** EPITECH PROJECT, 2024
** init_map
** File description:
** init_map
*/

#include "my.h"

static sfFloatRect *init_frect(float left, float top, float width,
    float height)
{
    sfFloatRect *rect = malloc(sizeof(sfFloatRect));

    rect->height = height;
    rect->width = width;
    rect->left = left;
    rect->top = top;
    return rect;
}

night_t *init_night(game_t *game, bool is_new)
{
    night_t *night = malloc(sizeof(night_t));
    char **res;

    night->clock = init_time();
    if (!is_new) {
        res = my_str_to_word_array(import_from_save("Time",
            game->savefilepath), "\n", 0);
        if (my_pointlen(res) != 1 || (my_getnbr(res[0]) == 0 &&
            res[0][0] != '0'))
            wrong_savefile(game->savefilepath, "###Time");
        night->clock->offset = my_getnbr(res[0]);
    } else
        night->clock->offset = 500;
    night->overlay = init_image(get_asset("night_overlay", game->assets),
        (sfVector2f){-9999, -9999}, 99999);
    night->time_mult = 1;
    night->sleep_zone = init_frect(11627, 10656, 200, 200);
    return night;
}
