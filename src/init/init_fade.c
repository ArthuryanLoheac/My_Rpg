/*
** EPITECH PROJECT, 2024
** init_map
** File description:
** init_map
*/

#include "my.h"

fade_t *init_fade(game_t *game)
{
    fade_t *fade = malloc((sizeof(fade_t)));

    fade->overlay = sfTransparent;
    fade->clock = init_time();
    fade->is_active = false;
    fade->img = init_image(get_asset("fade_overlay", game->assets),
        (sfVector2f){-9999, -9999}, 99999);
    return fade;
}
